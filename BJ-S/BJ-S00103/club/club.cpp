#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n,a[N],b[N],c[N];//input for each group
int cnt2,cnt3;//if ai2,ai3==0
int ans;
void fun1(){
    int ca=0,cb=0,cc=0;//club,0=ca,1=cb,2=cc
    int temp=0;
    ans=0;
    int e=1;
    for(int i=1;i<=n;i++){
        e=e*3;
    }
    //cout<<e;//test
    int f;
    for(int i=0;i<=e;i++){
		ca=0,cb=0,cc=0,temp=0,f=1;//begin
        for(int j=1;j<=n;j++){
			//cout<<(i/f)%3<<endl;//test2
            if((i/f)%3==2){
                cc++;
                temp+=c[j];
            }else if((i/f)%3==1){
                cb++;
                temp+=b[j];
            }else{
                ca++;
                temp+=a[j];
            }
            f*=3;
        }
        //cout<<ca<<" "<<cb<<endl;//test3
        if(ca<=n/2&&cb<=n/2&&cc<=n/2){
            ans=max(ans,temp);
        }
    }
    printf("%d\n",ans);
}
void fun2(){
    int ca=0,cb=0;//club,1=ca,0=cb
    int temp=0;
    ans=0;
    for(long long i=0;i<=((1<<n)-1);i++){
		ca=0,cb=0,temp=0;//begin
        for(long long j=1;j<=n;j++){
			//cout<<(i>>(j-1))%2<<endl;//test2
            if((i>>(j-1))%2==1){
                ca++;
                temp+=a[j];
            }else{
                cb++;
                temp+=b[j];
            }
        }
        //cout<<ca<<" "<<cb<<endl;//test3
        if(ca<=n/2&&cb<=n/2){
            ans=max(ans,temp);
        }
    }
    printf("%d\n",ans);
}
void funn2(){
	int temp=0,ca=0,cb=0,cc=0,ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			temp=0,ca=0,cb=0,cc=0;
			if(i==1){
				ca++;
				temp+=a[1];
				if(j==1){
					ca++;
					temp+=a[2];
				}else if(j==2){
					cb++;
					temp+=b[2];
				}else{
					cc++;
					temp+=c[2];
				}
			}
			if(i==2){
				cb++;
				temp+=b[1];
				if(j==1){
					ca++;
					temp+=a[2];
				}else if(j==2){
					cb++;
					temp+=b[2];
				}else{
					cc++;
					temp+=c[2];
				}
			}
			if(i==3){
				cc++;
				temp+=c[1];
				if(j==1){
					ca++;
					temp+=a[2];
				}else if(j==2){
					cb++;
					temp+=b[2];
				}else{
					cc++;
					temp+=c[2];
				}
			}
			if(ca<=n/2&&cb<=n/2&&cc<=n/2){
				ans=max(ans,temp);
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
        ans=0,cnt2=0,cnt3=0;//begin
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            if(b[i]==0){
                cnt2++;
            }
            if(c[i]==0){
                cnt3++;
            }
        }
        //special n=2
        if(n==2){
			funn2();
			continue;
		}
        //cout<<cnt2<<" "<<cnt3;//test1
        //specialA
        if(cnt2==n&&cnt3==n){
            sort(a+1,a+n+1);
            for(int i=n;i>(n/2);i--){
                ans+=a[i];
            }
            printf("%d\n",ans);
            continue;
        }//done
        //specialB
        if(cnt3==n){
            fun2();
            //printf("%d\n",fun2(n));
            continue;
        }
        //normal
		fun1();
	}
	return 0;
}
