#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
struct sss {
	int a,b,c;
	int choice;
}s[100005];
bool cmp(sss x,sss y){
	return (x.a-x.b)<(y.a-y.b);
}
bool cmb(sss x,sss y){
	return (x.b-x.c)<(y.b-y.c);
}
bool cmq(sss x,sss y){
	return (x.c-x.a)<(y.c-y.a);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum1=0,sum2=0,sum3=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c)
				sum1++,ans+=s[i].a,
				s[i].choice=1;
			if(s[i].b>=s[i].a&&s[i].b>=s[i].c)
				sum2++,ans+=s[i].b,
				s[i].choice=2;
			if(s[i].c>=s[i].b&&s[i].c>=s[i].a)
				sum3++,ans+=s[i].c,
				s[i].choice=3;
			
		}
			
		
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(s[i].choice==1){
					if(sum1<=n/2&&s[i].a>=s[i].b) break;
					ans-=(s[i].a-s[i].b);
					sum1--;
					s[i].choice=2;
					sum2++;	
				}
				
			}
			
			sort(s+1,s+n+1,cmb);
			for(int i=1;i<=n;i++){
				
				if(s[i].choice==2){
					if(sum2<=n/2&&s[i].b>=s[i].c) break;
					ans-=(s[i].b-s[i].c);
					sum2--;
					sum3++;
					s[i].choice=3;
				}	
			}
			
			sort(s+1,s+n+1,cmq);
			for(int i=1;i<=n;i++){
				if(s[i].choice==3){
					if(sum3<=n/2&&s[i].c>=s[i].a) break;
					ans-=(s[i].c-s[i].a);
					sum3--;
					sum1++;
					s[i].choice=3;
				}
			}
			
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++)
			{
				if(s[i].choice==1){
					if(sum1<=n/2&&s[i].a>=s[i].b) break;
					ans-=(s[i].a-s[i].b);
					sum1--;
					s[i].choice=2;
					sum2++;	
				}
				
			}
			
			sort(s+1,s+n+1,cmb);
			for(int i=1;i<=n;i++){
				
				if(s[i].choice==2){
					if(sum2<=n/2&&s[i].b>=s[i].c) break;
					ans-=(s[i].b-s[i].c);
					sum2--;
					sum3++;
					s[i].choice=3;
				}	
			}
			
			sort(s+1,s+n+1,cmq);
			for(int i=1;i<=n;i++){
				if(s[i].choice==3){
					if(sum3<=n/2&&s[i].c>=s[i].a) break;
					ans-=(s[i].c-s[i].a);
					sum3--;
					sum1++;
					s[i].choice=3;
				}
					
				
				
			}
		
		cout<<ans<<"\n";
		
	}


	return 0;
}

