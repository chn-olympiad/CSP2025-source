#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans=0;



int cc(int z,int b,int maxn,int zz,int pos){
	if(b==z,zz>2*maxn){
		ans++;
		return 0;
	}
	if(b==z,zz<=2*maxn)return 0;
	cc(z,b+1,max(maxn,a[pos]),zz+a[pos],pos+1);
	cc(z,b,maxn,zz,pos+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	//sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		cc(i,1,-1,0,1);
	}
	cout << ans;
	return 0;
}
