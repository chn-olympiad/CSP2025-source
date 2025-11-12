#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,num,h,l;
struct node{
	int val,id;
}a[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			num=i;
			break;
		}
	}
	if(num%n==0)l=num/n;
	else l=num/n+1;
	if(l%2==1)h=num-(l-1)*n;
	else h=n-(num-(l-1)*n)+1;
	cout<<l<<" "<<h;
	return 0;
}