#include<bits/stdc++.h>
using namespace std;
const int maxn=114;
int n,m,a[maxn],t,rc=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i];
	int i=1,j=1;
	while(a[rc]!=t){
		if(j==n){
			j=1,i++;
		}else{
			j++;
		}
		rc++;
	}
	if(i&1){
		cout<<i<<' '<<j;
	}else{
		cout<<i<<' '<<n-j+1;
	}
	return 0;
}
