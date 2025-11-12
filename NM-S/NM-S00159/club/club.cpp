#include<bits/stdc++.h>
using namespace std;
struct x {int n,m;};
struct y {int i[3];x j[3];} nim[100100];
bool cmp(x a,x b) {if(a.m!=b.m) return a.m>b.m;else return a.n<b.n;}
bool cmp1(y a,y b) {if(a.j[0].m!=b.j[0].m) return a.j[0].m>b.j[0].m;else return a.j[1].n<b.j[1].n;
}
vector<y>v[4];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	cin>>t;
	while(t--) {
		cin>>n;
		ans=0;
		v[0].clear();
		v[1].clear();
		v[2].clear();
		for(int a=0; a<n; a++) {
			cin>>nim[a].i[0]>>nim[a].i[1]>>nim[a].i[2];
			nim[a].j[0].n=1;
			nim[a].j[1].n=2;
			nim[a].j[2].n=3;
			nim[a].j[0].m=nim[a].i[0];
			nim[a].j[1].m=nim[a].i[1];
			nim[a].j[2].m=nim[a].i[2];
			sort(nim[a].j,nim[a].j+3,cmp);
			v[nim[a].j[0].n].push_back(nim[a]);
		}
		
		sort(v[1].begin(),v[1].end(),cmp1);
		while(v[1].size()>n/2) {
			y tmp=v[2][v[1].size()-1];
			tmp.j[0]=tmp.j[1];
			tmp.j[1]=tmp.j[2];
			v[tmp.j[0].n].push_back(tmp);
			v[1].pop_back();
		}
		sort(v[2].begin(),v[2].end(),cmp1);
		while(v[2].size()>n/2) {
			y tmp=v[2][v[2].size()-1];
			tmp.j[0]=tmp.j[1];
			tmp.j[1]=tmp.j[2];
			v[tmp.j[0].n].push_back(tmp);
			v[2].pop_back();
		}
		sort(v[3].begin(),v[3].end(),cmp1);
//		for(int a=1; a<=3; a++) for(int b=0; b<v[a].size(); b++) ans+=v[a][b].j[0].m;
//		cout<<ans<<endl;
	}
	return 0;
}
