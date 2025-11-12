#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(x,y) memset((x),(y),sizeof((x)))
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=1e5+5;
int n,s,s1,s2,s3,b[5],f[N][5],g[N];
struct node{
	int x,y,z,mx,id;
}a[N];
bool cmp(node x,node y){
	return x.mx>y.mx;
}
bool cmp2(node x,node y){
	return x.y>y.y;
}
bool cmp3(node x,node y){
	return x.z>y.z;
}
signed main(){
	FILE("club")
//	file("club2")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		cin>>n;s=0;memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));int m=n/2;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			int maxx=max({a[i].x,a[i].y,a[i].z});
			a[i].mx=maxx;
			if(maxx==a[i].x){
				b[1]++;a[i].id=1;
			}
			else if(maxx==a[i].y){
				b[2]++;a[i].id=2;
			}
			else if(maxx==a[i].z){
				b[3]++;a[i].id=3;
			}
			s+=maxx;
		}
//		cout<<s<<"\n";
		if(b[1]<=n/2 && b[2]<=n/2 &&b[3]<=n/2){
			cout<<s<<"\n";continue;
		}s=0;memset(b,0,sizeof(b));
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(b[1]==m && a[i].id==1){
				int maxx=max({a[i].y,a[i].z});
				if(a[i].y==maxx){
					if(b[2]==m){
						s+=a[i].z;
						b[3]++;
					}
					else{
						s+=a[i].y;
						b[2]++;
					}
				}
				else{
					if(b[3]==m){
						s+=a[i].y;
						b[2]++;
					}
					else{
						s+=a[i].z;b[3]++;
					}
				}
			}
			else if(b[2]==m && a[i].id==2){
				int maxx=max({a[i].x,a[i].z});
				if(a[i].x==maxx){
					if(b[1]==m){
						s+=a[i].z;
						b[3]++;
					}
					else{
						s+=a[i].x;
						b[1]++;
					}
				}
				else{
					if(b[3]==m){
						s+=a[i].x;
						b[1]++;
					}
					else{
						s+=a[i].z;b[3]++;
					}
				}
			}
			else if(b[3]==m && a[i].id==3){
				int maxx=max({a[i].y,a[i].x});
				if(a[i].y==maxx){
					if(b[2]==m){
						s+=a[i].x;
						b[1]++;
					}
					else{
						s+=a[i].y;
						b[2]++;
					}
				}
				else{
					if(b[1]==m){
						s+=a[i].y;
						b[2]++;
					}
					else{
						s+=a[i].x;b[1]++;
					}
				}
			}
			else{
				s+=a[i].mx;
				b[a[i].id]++;
//				cout<<a[i].mx<<" "<<a[i].id<<"\n";
			}
		}
		for(int i=1;i<=n;i++){
			if(b[1]!=m){
				f[i][0]=max({f[i-1][1],f[i-1][2],f[i-1][0]})+a[i].x;
				if(f[i][0]==f[i-1][0]+a[i].x){
					b[1]++;
				}
			}
			else{
				f[i][0]=max(f[i-1][1],f[i-1][2])+a[i].x;
			}
			if(b[2]!=m){
				f[i][1]=max({f[i-1][0],f[i-1][2],f[i-1][1]})+a[i].y;
				if(f[i][1]==f[i-1][1]+a[i].y){
					b[2]++;
				}
			}
			else{
				f[i][1]=max(f[i-1][0],f[i-1][2])+a[i].y;
			}
			if(b[3]!=m){
				f[i][2]=max({f[i-1][0],f[i-1][2],f[i-1][1]})+a[i].y;
				if(f[i][2]==f[i-1][2]+a[i].z){
					b[3]++;
				}
			}
			else{
				f[i][2]=max(f[i-1][0],f[i-1][1])+a[i].z;
			}
			
		}
		cout<<max({s,f[n][0],f[n][1],f[n][2]})<<"\n";
	}
	return 0;
}
/*
15480 0 0 1
9901 0 1 0
6362 0 1 2
10480 0 1 3
6516 0 2 3
9119 1 2 3
12689 1 3 3
16544 1 4 3
18712 1 4 4
9015 2 4 4
17042 2 4 5
=131860

*/
