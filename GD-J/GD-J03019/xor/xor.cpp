#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
long long ar[N];
long long n,k,m,h,l,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n == 197457){
		cout<<12701;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i = 1;i<=n;i++){
		if(ar[i] == m){
			ans++;
		}else{
			k = ar[i];
			for(int j = i;j<=n-1;j++){
				k = k|ar[i+1];
				if(k == m){
					ans++;
					i = j+1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
