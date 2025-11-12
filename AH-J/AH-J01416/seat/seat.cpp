#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
struct node{
	int n,c;
}a[1001];
bool cmp(node x,node y){
	return x.n>y.n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i].n;
		a[i].c=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i].c==1){
			cnt++;
			break;
		}
		cnt++;
	}
	int x=(cnt-1)/m+1;
	int y=cnt%m;
	if(y==0){
		y=n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
