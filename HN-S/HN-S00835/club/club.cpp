#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],a1;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			a1+=a[i];
		}
		cout<<a1;
	}
	return 0;
}
