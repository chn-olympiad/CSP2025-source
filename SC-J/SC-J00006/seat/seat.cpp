#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p,q;
int a[205],b[15][15];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==p)	q=n*m-i+1;
	}
	int num=1,i=0,j=1;
	for(int k=1;k<=q;k++){
		if(k%n==1&&k!=1){
			j+=1;
			num=0-num;
		}
		else{
			i+=num;
		}
	}
	cout<<j<<" "<<i;
	return 0;
} 