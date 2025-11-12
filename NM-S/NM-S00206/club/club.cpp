#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 +10;
long long vis[N];
void solve(){
	long long T;
	cin >> T;
	while(T--){
		long long n;
		cin >> n;
		long long ans=0;
		vector<long long> a,b,c;
		long long n1=0,n2=0,n3=0;
		for(long long i=1;i<=n;i++){
			long long x,y,z;
			cin >> x >> y >> z;
			long long p;
			if(x>max(y,z)){
				p=abs(min(y-x,y-z));
			}else if(y>max(x,z)){
				p=abs(min(z-x,z-y));
			}else if(z>max(x,y)){
				p=abs(min(x-y,x-z));
			}
		    ans+=(max(x,max(y,z)));
			vis[1]=p;
			if(x==max(y,z)){
				a.push_back(i);
				n1++;
			}
			else if(y==max(x,z)){
				b.push_back(i);
				n2++;
			}
			else{
				c.push_back(i);
				n3++;
			}
			
		}
		if(n1<=n/2&&n2<=n/2&&n3<=n/2) cout << ans << "\n";
		else{
			if(n1>n/2){
				long long tep[N];
				for(long long i=0;i<a.size();i++){
					tep[i]=vis[a[i]];
				} 
				sort(tep,tep+a.size());
				for(long long i=0;i<a.size()-n/2;i++){
					ans-=tep[i];
				}
			}else if(n2>n/2){
				long long tep[N];
				for(long long i=0;i<b.size();i++){
					tep[i]=vis[b[i]];
				} 
				sort(tep,tep+b.size());
				for(long long i=0;i<b.size()-n/2;i++){
					ans-=tep[i];
				}
			}else{
				int tep[N];
				for(long long i=0;i<c.size();i++){
					tep[i]=vis[c[i]];
				} 
				sort(tep,tep+c.size());
				for(long long i=0;i<c.size()-n/2;i++){
					ans-=tep[i];
				}
			}
		}
		cout << ans << "\n";
	}
	fclose(stdin);
	fclose(stdout);
} 
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}
