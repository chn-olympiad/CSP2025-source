#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k,ss=0;
	cin >> n>>k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=n;i>=1;i--){
		long long s=0;
		for(int j=i;j<=n and !vis[j];j++){
			s=s^a[j];
			if(s==k){
				vis[i]=1;
				ss++;
				break;
			}
		}
	}
	cout << ss;
}
