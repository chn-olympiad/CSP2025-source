#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	int b;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b>>b;
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=n/2;i--){
		maxn+=a[i];
	}
	cout<<maxn;
}
