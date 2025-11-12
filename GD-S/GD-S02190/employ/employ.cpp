#include<bits/stdc++.h>
using namespace std;
const int N=500+33;
const int P=998224353; 
int n,m;
char c[N];
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	for(int i=1;i<=m;i++){
		ans*=i%P;
	}
	cout<<ans;
	return 0;
}
