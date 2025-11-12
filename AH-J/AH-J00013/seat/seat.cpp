#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int R,now;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[++now]==R){
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(a[++now]==R){
					cout << i << " " << j;
					return 0;
				}
			}		
		}
	}
	return 0;
}
