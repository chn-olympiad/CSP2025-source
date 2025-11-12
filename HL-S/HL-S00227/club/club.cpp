#include <bits/stdc++.h>
using namespace std;
int cn;
struct club{
	int now;
	int v[3];
	int lm;
	int ls;
	int ms;
}m[100005];
int lar(int x,int y,int z){
	if(x>=y&&x>=z){
		cn=1;
		return max(x,max(y,z));
	}
	if(y>=x&&y>=z){
		cn=2;
		return max(x,max(y,z));
	}
	if(z>=y&&z>=x){
		cn=3;
		return max(x,max(y,z));
	}
}
int sma(int x,int y,int z){
	if(x<=y&&x<=z){
		cn=1;
		return min(x,min(y,z));
	}
	if(y<=x&&y<=z){
		cn=2;
		return min(x,min(y,z));
	}
	if(z<=y&&z<=x){
		cn=3;
		return min(x,min(y,z));
	}
}
int mid(int x,int y,int z){
	if(x>y&&x<z || x<y && x>z){
		cn=1;
		return x;
	}
	if(y>x&&y<z || y<x && y>z){
		cn=2;
		return y;
	}
	if(z>y&&z<x || z<y && z>x){
		cn=3;
		return z;
	}
}
bool cmp1(club a,club b){
	return a.lm<b.lm;
}
bool cmp2(club a,club b){
	return a.ls<b.ls;
}
bool cmp3(club a,club b){
	return lar(a.v[0],a.v[1],a.v[2]) >= lar(b.v[0],b.v[1],b.v[2]);
}
int s[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i =0 ;i<n;i++){
			cin >> m[i].v[0]>>m[i].v[1]>>m[i].v[2];
			m[i].lm = lar(m[i].v[0],m[i].v[1],m[i].v[2])-mid(m[i].v[0],m[i].v[1],m[i].v[2]);
			m[i].ls = lar(m[i].v[0],m[i].v[1],m[i].v[2])-sma(m[i].v[0],m[i].v[1],m[i].v[2]);
			m[i].ms = mid(m[i].v[0],m[i].v[1],m[i].v[2])-sma(m[i].v[0],m[i].v[1],m[i].v[2]);
		}
		sort(m,m+n,cmp2);
		sort(m,m+n,cmp1);
		sort(m,m+n,cmp3);
		for(int i = 0;i<n;i++){
			lar(m[i].v[0],m[i].v[1],m[i].v[2]);
			if(s[cn]<n/2){
				m[i].now = cn;
				s[cn]++;
				continue;
			}
			mid(m[i].v[0],m[i].v[1],m[i].v[2]);
			if(s[cn]<n/2){
				m[i].now = cn;
				s[cn]++;
				continue;
			}
			sma(m[i].v[0],m[i].v[1],m[i].v[2]);
			if(s[cn]<n/2){
				m[i].now = cn;
				s[cn]++;
				continue;
			}
		}
		int ans=0;
		for(int i = 0;i<n;i++){
			//cout << m[i].now<<endl;
			ans += m[i].v[m[i].now-1];
			//cout << m[i].v[m[i].now-1]<<" ";
		}
		cout << ans << endl;
	}
}
