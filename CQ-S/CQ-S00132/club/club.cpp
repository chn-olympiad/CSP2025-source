#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll x,y,z;
}a[10001];
ll q[10001],p[10001],k[10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll n;
	while(cin>>n){ 
		int sum=0; 
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z) sum+=a[i].x;
			else if(a[i].y>a[i].x&&a[i].y>a[i].z) sum+=a[i].y;
			else if(a[i].z>a[i].x&&a[i].z>a[i].x) sum+=a[i].z;
			else sum+=a[i].x; 
		}
		cout<<sum<<endl;
	}
	return 0;
}

