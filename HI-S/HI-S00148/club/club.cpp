#include<bits/stdc++.h>
using namespace std;
struct club{
	int f,s,t;
}a[1000001];
int mx=0,n;
int count(int xx,int x,int y,int z,int k){
	mx=max(mx,k);
	if(x){
		count(xx+1,x-1,y,z,k+a[xx+1].f);
	}
	if(y){
		count(xx+1,x,y-1,z,k+a[xx+1].s);
		}
	if(z){
		count(xx+1,x,y,z-1,k+a[xx+1].t);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n;
		vector<int> x,y,z;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
		}
		int cnt=n/2;
		count(1,cnt-1,cnt,cnt,a[1].f);
		count(1,cnt,cnt-1,cnt,a[1].s);
		count(1,cnt,cnt,cnt-1,a[1].t);
		cout<<mx<<endl;
	}
	return 0;
}
