#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int fa;
	bool xh=false;
}a[105];
bool cmp(node x,node y){
	return x.fa>y.fa;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1].fa;
	a[1].xh=true;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].fa;
	}
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			k++;
			if(a[k].xh){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			k++;
			if(a[k].xh){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
} 