#include<bits/stdc++.h>
using namespace std;
struct st{
	int x,y;
}a[110];
bool cmp(st x,st y){
	return x.y>y.y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].y;
		a[i].x=i;
	}
	sort(a+1,a+n*m,cmp);
	int cnt;
	for(int i=1;i<=n*m;i++){
		if(a[i].x==1){
			cnt=i;
			break;
		}
	}
	cnt--;
	int xx=cnt/n,yy=cnt%n;
	int hang,lie;
	if(xx%2==0)hang=1+yy;
	else hang=n-yy;
	cout<<xx+1<<" "<<hang;
	return 0;
} 
