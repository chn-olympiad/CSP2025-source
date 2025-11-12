#include<bits/stdc++.h>
using namespace std;
struct st{
	int s,x,y;
};
const int N=110;
int n,m,rs;
st a[N];
bool cmp(st a,st b){
	return a.s>b.s;
}
int find(int t){
	int i;
	for(i=1;i<=n*m;i++){
		if(a[i].s==rs){
			break;
		}
	}
	return i;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		if(i==1){
			rs=a[i].s;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		a[i].x=(i-1)/n+1;
		if(a[i].x%2==1){
			a[i].y=i-(a[i].x-1)*n;
		}else{
			a[i].y=i-(a[i].x-1)*n;
			a[i].y=n-a[i].y+1;
		}
		//cout<<a[i].s<<' '<<a[i].x<<' '<<a[i].y<<'\n';
	}
	int idx=find(rs);
	cout<<a[idx].x<<' '<<a[idx].y;
	return 0;
}
