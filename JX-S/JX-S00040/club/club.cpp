#include<bits/stdc++.h>
using namespace std;
int t,n,l,z,zz,zzz,h,b,an;
int a[100055][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		t--;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		l=3;b=n/2;an=0;
		map<pair<pair<int,int>,int>,int>p;
		queue<pair<pair<int,int>,pair<int,int> > >m;
		m.push(make_pair(make_pair(1,0),make_pair(0,a[1][1])));
		m.push(make_pair(make_pair(0,1),make_pair(0,a[1][2])));
		m.push(make_pair(make_pair(0,0),make_pair(1,a[1][3])));
		for(int i=2;i<=n;i++){
			for(int v=1;v<=l;v++){
				z=m.front().first.first;
				zz=m.front().first.second;
				zzz=m.front().second.first;
				h=m.front().second.second;
				m.pop();
				
				if(h>=p[make_pair(make_pair(z,zz),zzz)]){
					p[make_pair(make_pair(z,zz),zzz)]=h;
					if(z<b){
						m.push(make_pair(make_pair(z+1,zz),make_pair(zzz,h+a[i][1])));
					}
					if(zz<b){
						m.push(make_pair(make_pair(z,zz+1),make_pair(zzz,h+a[i][2])));
					}
					if(zzz<b){
						m.push(make_pair(make_pair(z,zz),make_pair(zzz+1,h+a[i][3])));
					}
				}
			}
			l=m.size();
		}
		for(int v=1;v<=l;v++){
			z=m.front().first.first;
			zz=m.front().first.second;
			zzz=m.front().second.first;
			h=m.front().second.second;
			m.pop();
			if(h>p[make_pair(make_pair(z,zz),zzz)]){
				p[make_pair(make_pair(z,zz),zzz)]=h;
				an=max(an,h);
			}
		}
		printf("%d\n",an);
	}
	return 0;
}
