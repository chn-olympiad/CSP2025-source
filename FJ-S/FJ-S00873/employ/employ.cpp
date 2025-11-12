#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
ll a[110];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			num++;
		}
	}
	if(n-num>=m){
		cout<<(n-num)*(n-num-1)/2;
	}else cout<<0;
	return 0;
} 
