#include<bits/stdc++.h>
using namespace std;
long long int T,n,a[100005],b[100005],c[100005],k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			k=k+a[i];
		}
		cout<<k;
		k=0;
	}
	return 0;
}
