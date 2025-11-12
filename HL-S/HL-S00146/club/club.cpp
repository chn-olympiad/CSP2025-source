#include<bits/stdc++.h>
using namespace std;
long long t,n,ans=-1;
const int N=10005;
struct node{
	int a1,a2,a3;
}a[N];
bool cmp(node x,node y){
	if(x.a1>y.a1) return x.a1>y.a1;
	else if(x.a2>y.a2) return x.a2>y.a2;
	eles return x.a3>y.a3;
}
int z(){
	return max(a[i].a3,max(a[i].a1,a[i].a2));
}
int main(){
	forrect(club.in,"r");
	forrect(club.out,"w");
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=z();
			if(ans<cnt) ans=cnt;
		}
	}
	cout<<ans;
	return 0;
}
