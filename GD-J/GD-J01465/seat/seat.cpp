#include<bits/stdc++.h>
using namespace std;
struct s{
	int c,id;
};
s d[101];
bool cmp(s&a,s&b){
	return a.c>b.c;
}
int n,m,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		d[i].id=i;
		cin>>d[i].c;
	}
	sort(d+1,d+1+n*m,cmp);
	for(int i=1;i<=n*m&&!k;i++)if(d[i].id==1)k=i;
	int x=(k+n-1)/n,y=k%n;
	if(y==0)y=n;
	if(x%2==0)y=n-y+1;
	cout<<x<<' '<<y;
	return 0;
}
