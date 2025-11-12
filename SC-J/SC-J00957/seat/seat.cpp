#include<bits/stdc++.h>
using namespace std;
int n,m;
struct yc{
	int id;
	int zhi;
} a[105];
bool cmp(yc x,yc y){
	return x.zhi>y.zhi;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].zhi;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cout<<a[i].id<<" "<<a[i].zhi<<"\n";
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int h=(i%n==0 ? n : i%n);
			int l=(i-h)/n+1;
			cout<<l<<" "<<(l%2==0 ? n+1-h : h);
		}
	}
}