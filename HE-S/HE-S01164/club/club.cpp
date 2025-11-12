#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int n_1,n_2,n_3,mxn;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].n_1>>a[i].n_2>>a[i].n_3;
			a[i].mxn=max(a[i].n_1,max(a[i].n_2,a[i].n_3));
		}
		if(n==2){
			cout<<max(a[1].n_1+a[2].n_2,max(a[1].n_1+a[2].n_3,max(a[1].n_2+a[2].n_3,max(a[1].n_3+a[2].n_1,a[1].n_3+a[2].n_2))));
		}
	}
	return 0;
}
