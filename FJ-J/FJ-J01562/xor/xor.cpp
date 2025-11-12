#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
long long a[N];
bool flag=false;
int ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		flag=false;
		int cnt=a[i];
		int m=i+1;
		while(m<=n){
			if(cnt==k){
				flag=true;
				break;
			}
			cnt=(cnt^a[m]);
			m++;
		}
		if(cnt==k) flag=true;
		if(flag){
			ans++;
			i=m-1;
		}
	}
	cout<<ans;
	return 0;
}
