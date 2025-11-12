#include<bits/stdc++.h>
using namespace std;

struct member{int a,b,c,ord,minu;}stu[100005];
inline void init(){
    for(int i=1;i<=100005;i++){
        stu[i].a=0,stu[i].b=0,stu[i].c=0,stu[i].minu=1000005;
    }
    return ;
}
bool cmp1(member x,member y){return x.a<y.a;}
bool cmp2(member x,member y){return x.b<y.b;}
bool cmp3(member x,member y){return x.c<y.c;}
bool cmp4(member x,member y){return x.minu<y.minu;}
bool cmp(int x,int y){return x>y;}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;cin>>t;
    while(t--){
        init();
        int n,ans=0;cin>>n;
        int cla=0,clb=0,clc=0;
        for(int i=1;i<=n;i++){
            cin>>stu[i].a>>stu[i].b>>stu[i].c;
            //save max
            int temp=max(max(stu[i].a, stu[i].b),stu[i].c);
            if(temp==stu[i].a){
                cla++,stu[i].ord=1;
            }
            else if(temp==stu[i].b)clb++,stu[i].ord=2;
            else    clc++,stu[i].ord=3;
			
            ans+=temp;

        }

        if(cla<=n/2&&clb<=n/2&&clc<=n/2){cout<<ans<<endl;continue;}
		
		
		int tempa=cla-n/2,tempb=clb-n/2,tempcc=clc-n/2;
        if(tempa>0){
			int temp=cla-n/2;
            for(int i=1;i<=n;i++){
				if(stu[i].ord==1){
					stu[i].minu=stu[i].a-max(stu[i].b,stu[i].c);
					
				}
				
			}
            sort(stu+1,stu+n+1,cmp4);
            
				for(int i=1;i<=temp;i++){
					ans-=stu[i].minu;
				}
				cout<<ans<<endl;continue;
			
        }
        
        else if(tempb>0){
			int temp=clb-n/2;
            for(int i=1;i<=n;i++){
				if(stu[i].ord==2){
					stu[i].minu=stu[i].b-max(stu[i].a,stu[i].c);
				}
			}
            sort(stu+1,stu+n+1,cmp4);
            
				for(int i=1;i<=temp;i++){
					ans-=stu[i].minu;
				}
				cout<<ans<<endl;continue;
        }
        
        else if(tempcc>0){
			int temp=clc-n/2;
            for(int i=1;i<=n;i++){
				if(stu[i].ord==3){
					stu[i].minu=stu[i].c-max(stu[i].a,stu[i].b);
				}
			}
            sort(stu+1,stu+n+1,cmp4);
            
				for(int i=1;i<=temp;i++){
					ans-=stu[i].minu;
				}
				cout<<ans<<endl;continue;
        }
        
        
    }



    return 0;
}
