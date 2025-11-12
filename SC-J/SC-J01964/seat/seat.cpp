#include <bits/stdc++.h>
using namespace std;
struct hh{
	int num,score;
}a[105];
bool cmp(hh x,hh y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].score;
		a[i].num=i;
	}
	sort(a,a+n*m,cmp);
	int tmp;
	for(int i=0;i<n*m;i++){
		if(a[i].num==0){
			tmp=i+1;
			break;
		}
	}
//	cout<<tmp<<'\n';
	int x=ceil(tmp*1.0/n);
	cout<<x<<' ';
	tmp=tmp-(ceil(tmp*1.0/n)-1)*n;
	if(x%2==0) cout<<n-(tmp-1);
	else cout<<tmp;
	return 0;
}