#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=a[1],c;
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==cnt){
				cout<<i<<' ';
				if(i%2)cout<<j;
				else cout<<m-j+1;
				return 0;
			}
		}
	}
} 
