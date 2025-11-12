#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int pp=0; pp<t; pp++){
		int n,ans=0;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(a[i],max(b[i],c[i]));
		}
		cout<<ans;
	}
}
