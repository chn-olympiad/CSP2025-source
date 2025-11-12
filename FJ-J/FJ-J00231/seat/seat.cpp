#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int sc[10005];
int s2[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	int R=sc[1];
	sort(sc+1,sc+1+n*m,cmp);
	int idx=1;
	for (int i=1;i<=m;i++){
		if (i%2==0){
			for (int j=n;j>=1;j--){
				if (sc[idx++]==R){
					c=j,r=i;
					break;
				}
			}
		}
		else {
			for (int j=1;j<=n;j++){
				if (sc[idx++]==R){
					c=i,r=j;
					break;
				}
			}
		}
	}
	cout<<c<<' '<<r;
	return 0;
}
