#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int q[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	if(k<=1){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(q[i]==1) ans++;
			}
			cout<<ans<<"\n";
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(q[i]==0) ans++;
				if(q[i]==1){
					if(q[i+1]==1){
						ans++;
						i+=2;
					}
					else if(q[i+2]==1){
						ans++;
						i+=3;
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
} 