#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1010],l[1010][1010],e=0,cnt=0;
int z(int x,int y){
	int s=a[x];
	for(int i=x+1;i<=y;i++){
		s=(s^a[i]);
	}
	return 0;
}
void t(int x,int y){
	if(x>e){
		cnt++;
		e=y;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l[i][j]=1e6;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			l[i][j]=z(i,j);
		}
	}
	for(int b=1;b<=n;b++){
		for(int m=b;m<=n;m++){
			if(l[b][m]==k){
				t(b,m);
			}
		}
	}
	cout<<cnt;
	return 0;
}
