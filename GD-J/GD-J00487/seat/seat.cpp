//O(n*m)
#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,g;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool f=1;
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(f){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==g){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==g){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		f=!f;
	}
	return 0;
}
