#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,f;
}a[105];
int cnt=1;
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	a[1].f=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;){
		for(int i=1;i<=n;){
			if(a[cnt].f==1){
				cout<<j<<' '<<i;
				return 0;
			}
			cnt++;
			i++;
		}
		j++;
		for(int i=n;i>=1;){
			if(a[cnt].f==1){
				cout<<j<<' '<<i;
				return 0;
			}
			cnt++;
			i--;
		}
		j++;
	}
	return 0;
} 
