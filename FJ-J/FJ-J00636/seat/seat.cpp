#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
struct node{
	int num,id;
}a[N];
bool cmp(node c,node d){
	return c.num>d.num;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("seat3.in","r",stdin);
//	freopen("seat.ans","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i].num;
			a[i].id=i;
	}
	int wo=a[1].num,now;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<a[i].num<<' ';
		if(a[i].num==wo){
			now=i;
			break;
		}
	}
	//cout<<now<<'\n';
	if((now/n)%2==1){
		if(now%n!=0)cout<<now/n+1<<' '<<n-(now-now/n*n)+1<<'\n';
		else cout<<now/n<<' '<<n<<'\n';
	}else{
		if(now%n!=0)cout<<now/n+1<<' '<<now-now/n*n<<'\n';
		else cout<<now/n<<' '<<1<<'\n';
	}
	return 0;
}
