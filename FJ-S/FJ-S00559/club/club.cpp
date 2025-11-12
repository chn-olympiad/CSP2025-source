#include<bits/stdc++.h>
using namespace std;
int t,n,a[101],b[101],c[101],ans[101];
int main(){
	reopen("club.in","r",stdin);
	reopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			a[j]=max(a[j],b[j]);
			a[j]=max(a[j],c[j]);
			ans[i]+=a[j];
		}
	}
	for(int i=0;i<t;i++) cout<<ans[i]<<endl;
	return 0;
}
