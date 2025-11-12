#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n,m;
int a[N*N];
int c[N][N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[++k]==x){
				cout<<i<<' '<<j<<'\n';
				return 0;
			}
		}
		i++;
		for(int j=m;j>=1;j--){
			if(a[++k]==x){
				cout<<i<<' '<<j<<'\n';
				return 0;
			}
		}
	}
	return 0;
} 
