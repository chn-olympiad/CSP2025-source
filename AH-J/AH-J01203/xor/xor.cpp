#include<bits/stdc++.h>
using namespace std;
long long a[500005],k;
int ans,n,b[25][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=20;j++){
			b[j][(a[i]&(1<<j))>0]++;
		}
		int f=1;
		for(int j=0;j<=20;j++){
			if(k&(1<<j)){
				if(!b[j][1]){
					f=0;
					break;
				}
			}
			else{
				if(!b[j][0]&&b[j][1]<2){
					f=0;
					break;
				}
			}
		}
		if(f){
			ans++;
			memset(b,0,sizeof(b));
		}
	}
	cout<<ans;
	return 0;
}
