#include<bits/stdc++.h>
using namespace std;

int n,t,c,m;
struct node{
	int a1,a2,a3;
}a[1000005];

int p1,p2,p3;

int main(){
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	cin>>t;
	while(t--){
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		for(int i=1;i<=n;i++){
			c+=max(max(a[i].a1,a[i].a2),a[i].a3);
		}
		cout<<c<<endl;
	}
	return 0;
}
