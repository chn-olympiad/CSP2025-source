#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e5+5;
ll k[5],n,s,more;
struct node{
	ll x,y,z,b;
}a[N];
bool cmpx(node a,node b){
	if(a.b==1&&b.b==1){
		ll w1=min(a.x-a.y,a.x-a.z);
		ll w2=min(b.x-b.y,b.x-b.z);
		return w1<w2;
	}
	else if(a.b==1)return 1;
	else return 0;
}
bool cmpy(node a,node b){
	if(a.b==2&&b.b==2){
		ll w1=min(a.y-a.x,a.y-a.z);
		ll w2=min(b.y-b.x,b.y-b.z);
		return w1<w2;
	}
	else if(a.b==2)return 1;
	else return 0;
}
bool cmpz(node a,node b){
	if(a.b==3&&b.b==3){
		ll w1=min(a.z-a.x,a.z-a.y);
		ll w2=min(b.z-b.x,b.z-b.y);
		return w1<w2;
	}
	else if(a.b==3)return 1;
	else return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		k[1]=k[2]=k[3]=s=0;
		for(int i=1;i<=n;i++)
			cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				a[i].b=1,k[1]++;
				s+=a[i].x;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				a[i].b=2,k[2]++;
				s+=a[i].y;
			}
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y){
				a[i].b=3,k[3]++;
				s+=a[i].z;
			}
		}
		if(k[1]>n/2){
			more=k[1]-n/2;
			sort(a+1,a+1+n,cmpx);
			for(int i=1;i<=more;i++)
				s-=min(a[i].x-a[i].y,a[i].x-a[i].z);
		}
		if(k[2]>n/2){
			more=k[2]-n/2;
			sort(a+1,a+1+n,cmpy);
			for(int i=1;i<=more;i++)
				s-=min(a[i].y-a[i].x,a[i].y-a[i].z);
		}
		if(k[3]>n/2){
			more=k[3]-n/2;
			sort(a+1,a+1+n,cmpz);
			for(int i=1;i<=more;i++)
				s-=min(a[i].z-a[i].y,a[i].z-a[i].x);
		}
		cout<<s<<'\n';
	}
    return 0;
}
