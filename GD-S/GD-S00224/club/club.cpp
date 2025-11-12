#include<bits/stdc++.h>
using namespace std;int t,n,m[100001],k[100001],i,s;
array<int,3>a[100001];vector<int>p[3];
main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	scanf("%d",&t);while(t--){
		scanf("%d",&n);p[0].clear();p[1].clear();p[2].clear();s=0;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			m[i]=max(a[i][0],max(a[i][1],a[i][2]));s+=m[i];
			if(m[i]==a[i][0])p[0].push_back(m[i]-max(a[i][2],a[i][1]));
			if(m[i]==a[i][1])p[1].push_back(m[i]-max(a[i][2],a[i][0]));
			if(m[i]==a[i][2])p[2].push_back(m[i]-max(a[i][0],a[i][1]));
		}if(p[0].size()*2>n){
			sort(p[0].begin(),p[0].end());
			for(i=0;i<p[0].size()-n/2;i++)s-=p[0][i];
		}if(p[1].size()*2>n){
			sort(p[1].begin(),p[1].end());
			for(i=0;i<p[1].size()-n/2;i++)s-=p[1][i];
		}if(p[2].size()*2>n){
			sort(p[2].begin(),p[2].end());
			for(i=0;i<p[2].size()-n/2;i++)s-=p[2][i];
		}printf("%d\n",s);
	}
}//Ren5Jie4Di4Ling5%
/*3
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
4 0 0*/
