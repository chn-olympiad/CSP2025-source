#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,t,a[100005],b[100005],c[100005];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int x=0,y=0,z=0,ans=0,dj[100005];
		for(int j=1;j<=n;j++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int j=1;j<=n;j++{
			ans+=max(a[j],max(b[j],c[j]));
		}
		for(int 
	}
	return 0;
}
