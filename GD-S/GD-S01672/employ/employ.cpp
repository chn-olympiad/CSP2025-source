#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char c[maxn];
int a[maxn];
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	long long sum=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]>1) sum++; 
	}
	long long ans=1;
	for(int i=2;i<=sum;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
} 
