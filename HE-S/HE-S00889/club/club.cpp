#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100001][3],ans[5],i,k,maxx;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(k=0;k<t;++k){
		cin>>n;
		for(i=0;i<n;++i){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			maxx=max(max(a[i][0],a[i][1]),a[i][2]);
		}
		cout<<maxx<<endl;
	}
	return 0;
}
