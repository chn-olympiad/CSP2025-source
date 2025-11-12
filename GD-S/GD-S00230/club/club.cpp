#include<bits/stdc++.h>
using namespace std;
int ans;
int n,t,a[3][100005],ma;
void js(int cs,int x,int y,int z,int zh){
	if(cs==n+1){
		ans=max(ans,zh);
		return;
	}
	if(zh+(n+1-cs)*ma<=ans)return;
	if(x==n/2){
		js(cs+1,x,y,z,zh+max(a[1][cs],a[2][cs]));
	}
	if(y==n/2){
		js(cs+1,x,y,z,zh+max(a[0][cs],a[2][cs]));
	}
	if(z==n/2){
		js(cs+1,x,y,z,zh+max(a[1][cs],a[0][cs]));
	}else if(a[0][cs]<a[1][cs]&&a[0][cs]<a[2][cs]){
		js(cs+1,x,y+1,z,zh+a[1][cs]);
		js(cs+1,x,y,z+1,zh+a[2][cs]);
	}else if(a[1][cs]<a[0][cs]&&a[1][cs]<a[2][cs]){
		js(cs+1,x+1,y,z,zh+a[0][cs]);
		js(cs+1,x,y,z+1,zh+a[2][cs]);
	}else{
		js(cs+1,x+1,y,z,zh+a[0][cs]);
		js(cs+1,x,y+1,z,zh+a[1][cs]);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(;t>0;t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			ma=max(a[0][i],max(a[1][i],max(a[2][i],ma)));
		}
		js(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
