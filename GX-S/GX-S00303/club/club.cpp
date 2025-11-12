#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
struct myd{
	int a,b,c;
}x[N];
int ca[N],cb[N],cc[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,cnta=0,cntb=0,cntc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b && x[i].a>=x[i].c){
				ans+=x[i].a;ca[++cnta]=x[i].a-max(x[i].b,x[i].c);
				
			}else{
				if(x[i].b>=x[i].a && x[i].b>=x[i].c){
					ans+=x[i].b;cb[++cntb]=x[i].b-max(x[i].a,x[i].c);
					
				}else{
					ans+=x[i].c;cc[++cntc]=x[i].c-max(x[i].b,x[i].a);
					
				}
			}
		}
		if(max(cnta,max(cntb,cntc))<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int cnt=0;
		if(cnta>n/2){
			sort(ca+1,ca+cnta+1);
			while(cnta>n/2){
				ans-=ca[++cnt];cnta--;
			}
		}
		if(cntb>n/2){
			sort(cb+1,cb+cntb+1);
			while(cntb>n/2){
				ans-=cb[++cnt];cntb--;
			}
		}
		if(cntc>n/2){
			sort(cc+1,cc+cntc+1);
			while(cntc>n/2){
				ans-=cc[++cnt];cntc--;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
