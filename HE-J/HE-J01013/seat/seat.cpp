#include<bits/stdc++.h>
using namespace std;
const int N=4e2+5;
struct miao{
	int fen,id;
}a[N];
bool cmp(miao a,miao b){
	return a.fen>b.fen;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].fen;a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int flag;
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){
			flag=i;break;
		}
	int hh=flag/n,ll=flag%n;
//	cout<<hh<<" "<<ll<<" "<<flag<<'\n';
	if(ll==0){
		if(hh%2==0)cout<<hh<<" 1";
		else cout<<hh<<" "<<n;
		return 0;
	}
	if(hh%2==1){
		cout<<hh+1<<" ";
		cout<<n-ll+1;
	}
	else{
		cout<<hh+1<<" ";
		cout<<ll;
	}
	return 0;
}
