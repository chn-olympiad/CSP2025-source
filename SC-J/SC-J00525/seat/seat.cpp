#include<bits/stdc++.h>
using namespace std;
const int MAXN=101;
int n,m;
int a[MAXN];
int r;
int x,y;
bool Greater(int k,int l){
	return k>l;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,Greater);
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
//			cout<<a[(i-1)*n+j]<<' ';
			if(a[(i-1)*n+j]==r){
				cout<<i<<' ';
				if(i%2){
					cout<<j;
				}else{
					cout<<n-j+1; 
				}
//				cout<<'\n';
			}
		}
	}
	return 0;
} 
//CCF保佑,弄不好真成信竞绝唱了 