#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,w=0;
	long long ans=1,sum=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0){
			w++;
		}
	}
	sort(c,c+n);
	if(n-w<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	for(int i=1;i<w;i++){
		sum*=i;
	}
	long long df=(ans-sum)%998244353;
	cout<<df;
	return 0;
} 
