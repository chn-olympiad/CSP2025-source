#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=0,ans=0;
	double m;
	cin>>n;
	long long a[5050];
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		m+=a[i];
		maxn=maxn>a[i]?maxn:a[i];
	}
	m/=2;
	for(int i=0;i<n;i++){
		if(m>a[i]) ans++;
	}
	if(ans==0) cout<<0;
	else cout<<1;
	return 0;
} 
