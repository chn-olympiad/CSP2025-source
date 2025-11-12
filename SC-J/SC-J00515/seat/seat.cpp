#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m;
struct node{
	int x;
	int f;
}a[maxn];
bool cmp(node xx,node yy){
	return xx.x>yy.x;
}
int cnt;
int t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].f=i;
	}
	sort(a+1,a+n*m+1,cmp);
	t=0;
	for(int j=1;j<=m;j+=2){
		cnt++;
		for(int i=1;i<=n;i++){
			int l=i+(cnt-1)*2*n;
			int r=2*n*cnt-(i-1);
			if(a[l].f==1){
				t=1;
				cout<<j<<" "<<i;
				break;
			}
			else if(a[r].f==1){
				t=1;
				cout<<j+1<<" "<<i;
				break;
			}
		}
		if(t){
			break;
		}
	}
	return 0;
}