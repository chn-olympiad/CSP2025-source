#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct node{
	int val,id;
}a[N*N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+l+1,cmp);
	int i=1,j=1,k=1;
	while(j<=m){
		if(a[k].id==1){
			cout<<j<<' '<<i;
			return 0;
		}
		k++;
		if(i==n&&j%2==1||i==1&&j%2==0){
			j++;
			continue;
		}
		if(j%2) i++;
		else i--;
	}
	return 0;
}
