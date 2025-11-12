#include <bits/stdc++.h>
using namespace std;
int t,n,sa,sb,sc,cnt,sum,op,c[100010];
struct no{
	int x,y,z,big;
}a[100010];
vector<int> va,vb,vc;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		va.clear(),vb.clear(),vc.clear(),sa=sb=sc=sum=cnt=op=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].big=max(a[i].x,max(a[i].y,a[i].z));
		}
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) sa++,va.push_back(i),sum+=a[i].x;
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) sb++,vb.push_back(i),sum+=a[i].y;
			else sc++,vc.push_back(i),sum+=a[i].z;
		}
		if(sa<=n/2&&sb<=n/2&&sc<=n/2){
			cout<<sum<<endl;
			continue;
		}
		if(sa>n/2){
			for(int i=0;i<sa;i++) c[++cnt]=a[va[i]].x-max(a[va[i]].y,a[va[i]].z);
			op=sa-n/2;
		}
		else if(sb>n/2){
			for(int i=0;i<sb;i++) c[++cnt]=a[vb[i]].y-max(a[vb[i]].x,a[vb[i]].z);
			op=sb-n/2;
		}
		else{
			for(int i=0;i<sc;i++) c[++cnt]=a[vc[i]].z-max(a[vc[i]].x,a[vc[i]].y);
			op=sc-n/2;
		}
		sort(c+1,c+1+cnt);
		for(int i=1;i<=op;i++) sum-=c[i];
		cout<<sum<<endl;
	}
	return 0;
}
/*
14:32 Game start!!!
14:42 I know it
15:12 nice

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
