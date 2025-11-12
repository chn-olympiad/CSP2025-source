#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int a[505];
long long sum=1;
int t[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}for(int i=1;i<=min(t[0],n);i++){
		t[0]+=t[i];
	}for(int i=2;i<=n-t[0];i++){
		sum*=i;
		sum%=998244353;
	}if(t[0]-n>=k)cout<<sum;
	else cout<<t[0]<<" "<<0;
	return 0;
} 
