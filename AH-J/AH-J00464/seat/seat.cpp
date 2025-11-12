#include<bits/stdc++.h>
using namespace std;
int n,m,t=1,cnt=1;
bool f;
struct kksk{
	int x,id;
}a[105];
bool cmp(kksk q,kksk w){
	return q.x>w.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cout<<a[i].x<<' '<<a[i].id<<' '<<'\n';
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<cnt<<'\n';
			if(a[cnt].id==1){
				cout<<i<<' '<<j;
				f=1;
				break;
			}
			if(t==1){
				cnt++;
			}else{
				cnt--;
			}
		}
		if(f){
			break;
		}
		if(t==1){
			cnt=(cnt-1)*2;
		}else{
			cnt=cnt+n+1;
		}
		t=-t;
	}
	return 0;
}
