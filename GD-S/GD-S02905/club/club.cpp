#include<bits/stdc++.h>
using namespace std;
const int MAXN=100000+5; 
int t,n,a[MAXN],b[MAXN],c[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		cout<<a[1]+b[n+1]+c[n+2]<<endl;
	}
	return 0;
} 
