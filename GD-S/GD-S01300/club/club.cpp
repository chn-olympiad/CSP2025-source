#include<bits/stdc++.h>
namespace zcy{
	using namespace std;
	const int MAXN=1e5+5;
	int fc,n;
	struct per{
		int a;
		int b;
		int c;
		int f1;
		int f2;
		void update(){
			if(a>b){
				if(a>c){
					if(b>c){
						f1=a,f2=b;
					}else{
						f1=a,f2=c;
					}
				}else{
					f1=c,f2=a;
				}
			}else{
				if(a>c){
					f1=b,f2=a;
				}else{
					if(b>c){
						f1=b,f2=c;
					}else{
						f1=c,f2=b;
					}
				}
			}
		}
		
		char best(){
			if(a>b){
				if(a>c){
					return 'a';
				}else{
					return 'c';
				}
			}else{
				if(a>c){
					return 'b';
				}else{
					if(b>c){
						return 'b';
					}else{
						return 'c';
					}
				}
			}
		}
	}arr[MAXN];
	
	bool cmp(per x,per y){
		if(x.f1-x.f2>y.f1-y.f2){
			return 1;
		}
		return 0;
	}
	
	void solve(){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>arr[i].a>>arr[i].b>>arr[i].c,arr[i].update();
		
		int goa=0,gob=0,goc=0;
		for(int i=1;i<=n;i++){
			char t=arr[i].best();
			if(t=='a')goa++;
			if(t=='b')gob++;
			if(t=='c')goc++;
		}
		if(goa>n/2){
			sort(arr+1,arr+1+n,cmp);
			int me=n/2;
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(arr[i].best()=='a'){
					if(me)me--,ans+=arr[i].f1;
					else ans+=arr[i].f2;
				}
				else ans+=arr[i].f1;
			}
			cout<<ans<<endl;
		}
		else if(gob>n/2){
			sort(arr+1,arr+1+n,cmp);
			int me=n/2;
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(arr[i].best()=='b'){
					if(me)me--,ans+=arr[i].f1;
					else ans+=arr[i].f2;
				}
				else ans+=arr[i].f1;
			}
			cout<<ans<<endl;
		}
		else if(goc>n/2){
			sort(arr+1,arr+1+n,cmp);
			int me=n/2;
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(arr[i].best()=='c'){
					if(me)me--,ans+=arr[i].f1;
					else ans+=arr[i].f2;
				}
				else ans+=arr[i].f1;
			}
			cout<<ans<<endl;
		}
		else{
			long long ans=0;
			for(int i=1;i<=n;i++)ans+=arr[i].f1;
			cout<<ans<<endl;
		}
	}
	
	int main(){
		#ifndef debug
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		#endif
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		int T;
		cin>>T;
		while(T--)solve();
		
		return 0;
	}
} 
int main(){
	zcy::main();
	return 0;
}
