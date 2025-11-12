#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id;
	int z;
}a[105];
bool cmp(node x,node y){
	return x.z>y.z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin>>a[i].z;
	}
	sort(a+1,a+1+n*m,cmp);
	int pos=0;
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){
			pos=i;
			break;
		}
	int li=(pos-1)/n+1,ha;
	if(((pos-1)/n)%2)ha=n-(pos-1)%n;
	else ha=(pos-1)%n+1;
	cout<<li<<' '<<ha;
	return 0;
}
