#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000],b[1000000],c[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			num+=max(max(a[i],b[i]),c[i]);
		}
		cout<<num<<'\n';
	}
	return 0;
}
