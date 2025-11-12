#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int c,int d){
	return c>d;
}
int r,pos;
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			pos=i;
			break;
		}
	}
	int c=pos/n;
	int y=pos%n;
	if(y!=0)c++;
	if(c%2==1){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(pos==i*n-n+j){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	else{
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(pos==i*n-n+j){
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}