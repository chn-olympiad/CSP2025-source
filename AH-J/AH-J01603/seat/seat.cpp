#include<bits/stdc++.h>
using namespace std;
int n,m,d=1,as;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int g;
			cin>>g;
			a[d++]=g;
			if(i==1&&j==1)as=g;
		}
	}
	sort(a+1,a+d+1,cmp);
	d=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[d++]==as){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[d++]==as){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
