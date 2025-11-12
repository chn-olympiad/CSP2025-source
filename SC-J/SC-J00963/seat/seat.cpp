#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

long long ans[N],cnt,a[N],b[N][N];
long long n,m,r;

bool qqq(int x,int y){
	return y < x;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	r = a[1];
	sort(a+1,a+1 + n*m,qqq);
	for(int i = 1,j = 1,k = 1;i <= n and j <= m and k <= n*m;k++){
////		cout<<r<<' '<<b[i][j]<<"\n";
		b[i][j] = a[k];
//		cout<<i<<' '<<j<<b[i][j]<<"\n";
		if(r == b[i][j]){
			cout<<i<<' '<<j;
		}		
		if(i%2!=0){
			j++;
		}else{
			j--;
		}
		if(j>m){
			i++;
			j = m;
		}
	}
}