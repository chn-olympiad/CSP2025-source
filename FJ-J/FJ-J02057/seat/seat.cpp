#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	int d=a[1],e=0;
	sort(a+1,a+k+1,greater<int>());
	for(int i=1;i<=k;i++){
		if(a[i]==d){
			e=i;
		}
	}
	int v=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				++v;
				if(v==e){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				++v;
				if(v==e){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
}
