#include<bits/stdc++.h>
using namespace std;
int t;
int n,ans;
bool a[100010];
struct NODE{
	int a,b,c;
}stud[100010];
bool cmp1(NODE x,NODE y){
	return x.a>y.a;
}
bool cmp2(NODE x,NODE y){
	return x.b>y.b;
}
bool cmp3(NODE x,NODE y){
	return x.c>y.c;
}
int ren1,ren2,ren3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stud[i].a>>stud[i].b>>stud[i].c;
		}
		if(n==2){
			int w=stud[1].a+stud[2].b;
			int e=stud[1].a+stud[2].c;
			int r=stud[1].b+stud[2].a;
			int t=stud[1].b+stud[2].c;
			int u=stud[1].c+stud[2].a;
			int o=stud[1].c+stud[2].b;
			w=max(w,e);
			r=max(r,t);
			u=max(u,o);
			ans=max(w,max(r,u));
			cout<<ans<<endl;
		}
		else{
				int ma=n/2;
				sort(stud+1,stud+n+1,cmp1);
				int j=0,sj=0;
				for(int i=1;i<=n;i++){
					if(j==ma){
						j=0;
						break;
					}	
					if(stud[i].a>=stud[i].b&&stud[i].a>=stud[i].c){
						ans+=stud[i].a;
						stud[i].a=stud[i].b=stud[i].c=0;
						j++;	
						sj++;
					}
				}
				j=0;
				sort(stud+1,stud+n+1,cmp2);
				for(int i=1;i<=n;i++){	
					if(j==ma){
						j=0;
						break;
					}
					if(stud[i].b>=stud[i].a&&stud[i].b>=stud[i].c){
						ans+=stud[i].b;
						stud[i].a=stud[i].b=stud[i].c=0;	
						j++;
						sj++;
					}
				}
				j=0;
				sort(stud+1,stud+n+1,cmp3);
				for(int i=1;i<=n;i++){
					if(j==ma){
							break;
					}
					if(stud[i].c>=stud[i].a&&stud[i].c>=stud[i].b){
						ans+=stud[i].c;
						stud[i].a=stud[i].b=stud[i].c=0;
						j++;
						sj++;
					}
				}
			cout<<ans<<endl;
		}
	}
	return 0;
} 