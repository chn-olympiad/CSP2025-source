#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,xx,yy,zz,ans,cnt;
struct node{
	int x,y,z,maxa,seca,mina,cnt;
}a[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cnt=ans=xx=yy=zz=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].cnt=0;
			a[i].maxa=max(max(a[i].x,a[i].y),a[i].z);
			a[i].mina=min(min(a[i].x,a[i].y),a[i].z);
			if(a[i].x==a[i].y||a[i].y==a[i].z)a[i].seca=a[i].y;
			else if(a[i].x==a[i].z)a[i].seca=a[i].x;
			else if(a[i].maxa>a[i].x&&a[i].x>a[i].mina)a[i].seca=a[i].x;
			else if(a[i].maxa>a[i].y&&a[i].y>a[i].mina)a[i].seca=a[i].y;
			else a[i].seca=a[i].z;
		}
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qx,qy,qz;
		for(int i=1;i<=n;i++){
			ans+=a[i].maxa;
			if(a[i].maxa==a[i].x){
				xx++;
				qx.push({a[i].maxa-a[i].seca,i});
			}
			else if(a[i].maxa==a[i].y){
				yy++;
				qy.push({a[i].maxa-a[i].seca,i});
			}
			else{
				zz++;
				qz.push({a[i].maxa-a[i].seca,i});
			}
			if(xx>n/2){
				int data=qx.top().first,id=qx.top().second;
				qx.pop();
				xx--;
				ans-=data;
			}
			else if(yy>n/2){
				int data=qy.top().first,id=qy.top().second;
				qy.pop();
				yy--;
				ans-=data;
			}
			else if(zz>n/2){
				int data=qz.top().first,id=qz.top().second;
				qz.pop();
				zz--;
				ans-=data;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
