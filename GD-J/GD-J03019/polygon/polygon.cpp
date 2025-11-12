#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
long long ar[N];
long long n,k,m,h,l,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n-1;i++){
		cin>>ar[i];
		ans+=ar[i];
	}
	cin>>ar[n];
	sort(ar+1,ar+1+n);
	if(ar[n]<ans){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
