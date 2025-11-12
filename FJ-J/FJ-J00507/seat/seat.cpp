#include<bits/stdc++.h>
using namespace std;
long long n,m,temp,pos,x,a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		temp=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp) pos=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				if((i-1)*n+j==pos) cout<<i<<" "<<j;
			}
			else{
				if((i-1)*n+n-j+1==pos) cout<<i<<" "<<n-j+1;
			}
		}
	}
	return 0;
}

