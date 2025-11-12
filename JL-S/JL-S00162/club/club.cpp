#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int t,n;
ll dp[10005];
struct node{
	int x,y,z;
}a[10005];
bool cmp(node a,node b){
	if(a.x<b.x) return true;
	else return false;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	ll sum=0;
	while(t>0){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			sum+=a[i].x;
		}
		t--;
		cout<<sum<<endl;
	}
	return 0;
}
//return 114514;
