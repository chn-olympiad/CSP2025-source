#include<bits/stdc++.h>
using namespace std;
long long n,m,k,xi,xj,l[110][110];
struct node{
	long long number,id;
}a[1010];
bool cmp(node x,node y){
	return x.number>y.number;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[k].number;
			if(k==0){
				p=a[k].number;
			}
			a[k].id=k;
			k++;
		}
	}
	sort(a,a+k,cmp);
	k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2!=0){
				l[i][j]=a[k].number;
			}
			else if(i%2==0){
				l[i][n-j+1]=a[k].number;
			}
			k++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(p==l[i][j]){
				cout<<i<<" "<<j;return 0;
			}
		}
	}
	return 0;
}
