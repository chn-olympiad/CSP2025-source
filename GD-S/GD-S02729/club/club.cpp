#include<bits/stdc++.h>
using namespace std;
int q[1000000],a[10],maxn,e[10][1000000],n;
void co(int s){
	int sum=0;
	for(int i=1;i<=s;i++){
		sum+=e[q[i]][i];
	}
	maxn=max(maxn,sum);
}
void f(int s,int m){
	if(s>m){
		co(m);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(a[i]<=n/2){
			a[i]++;
			q[s]=i;
			f(s+1,m);
			a[i]--;
		}
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		maxn=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				cin>>e[k][j];
			}
		}
		f(1,m);
		cout<<maxn<<'\n';
	}
	return 0;
} 
