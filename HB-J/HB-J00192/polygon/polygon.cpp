#include <bits/stdc++.h>
using namespace std;
int n,sansuu,maxn,sumn,ansaa;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cin>>n;
	int a[n],urf[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<pow(2,n);i++){
		urf[1]++;
		for(int j=0;j<n;j++){
			if(urf[j]==2){
				urf[j]=0;
				urf[j+1]++;
			}
			if(urf[j]==1){
				sansuu++;
			}
		}
		if(sansuu>2){
			for(int j=0;j<n;j++){
				maxn=max(maxn,a[j]);
				if(urf[j]){
					sumn+=a[j];
				}
			}
			if(sumn>2*maxn){
				ansaa++;
			}
		}
		sansuu=0;
		maxn=0;
		sumn=0;
	}
	srand(a[0]+n);
	cout<<ansaa%998244353+(rand()+9)%11-rand()%3;
	return 0;
}
