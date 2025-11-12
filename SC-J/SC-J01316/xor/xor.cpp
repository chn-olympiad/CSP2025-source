#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+15;
bool used[N],used2[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool is0=1,is01=1;
	int a,b;
	cin>>a>>b;
	int c[a];
	for(int i = 0; i < a; i++){
		cin>>c[i];
		if(c[i]!=1) is0=0;
		if(c[i]!=1 && c[i]!=0) is01=0;
	}
	if(is0){
		cout<<a/2;
		return 0;
	}
	if(is01){
		if(b==0){
			int ans=0,ans2=0,a222=0;
			for(int i = 0; i < a; i++){
				if(c[i]==0){
					a222++;
					used[i]=1;
					used2[i]=1;
				}
			}
			for(int i = 0; i < a-1; i++){
				if(used[i] || used[i+1]) continue;
				if(c[i]==c[i+1]){
					ans++;
					used[i]=1;
					used[i+1]=1;
				}
			}
			for(int i = 1; i < a-1; i++){
				if(used2[i] || used2[i+1]) continue;
				if(c[i]==c[i+1]){
					ans2++;
					used2[i]=1;
					used2[i+1]=1;
				}
			}
			cout<<max(ans+a222,ans2+a222);
			return 0;
		}
		else{
			int ans=0,ans2=0,a222=0;
				for(int i = 0; i < a; i++){
				if(c[i]==1){
					a222++;
					used[i]=1;
					used2[i]=1;
				}
			}
			for(int i = 0; i < a-1; i++){
				if(used[i] || used[i+1]) continue;
				if(c[i]!=c[i+1]){
					ans++;
					used[i]=1;
					used[i+1]=1;
				}
			}
			for(int i = 1; i < a-1; i++){
				if(used2[i] || used2[i+1]) continue;
				if(c[i]!=c[i+1]){
					ans2++;
					used2[i]=1;
					used2[i+1]=1;
				}
			}
			cout<<max(ans+a222,a222+ans2);
			return 0;
		}
	}
	return 0;
}