#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],s[15][15];
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1],y=1;
	sort(a+1,a+1+n*m,cmp);
	bool fast=false;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			s[j][i]=a[y];
			y++;
		}
		i++;
		for (int j=m;j>=1;j--){
			s[j][i]=a[y];
			y++;
		}
		if (fast==true){
			break;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if(s[j][i]==x){
				cout<<i<<' '<<j;
				fast=true;
				break;
			}
		}
		if (fast==true){
			break;
		}
		i++;
		for (int j=m;j>=1;j--){
			if(s[j][i]==x){
				cout<<i<<' '<<j;
				fast=true;
				break;
			}
		}
		if (fast==true){
			break;
		}
	}
	return 0;
}

