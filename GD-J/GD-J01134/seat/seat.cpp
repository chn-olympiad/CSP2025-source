#include<bits/stdc++.h>
using namespace std;
long long n,m,x=1,s;
long long num[110];
long long a[15][15];
bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long s=n*m;
	for(int i=1;i<=s;i++){
		cin>>num[i];
	}
	s=num[1];
	sort(num+1,num+1+s,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				a[i][j]=num[x];
				x++;
			}
		}else{
			for(int i=n;i>=1;i--){
				a[i][j]=num[x];
				x++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==s){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
