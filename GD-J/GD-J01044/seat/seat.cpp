#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int s=a[1],x=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				if(a[++x]==s){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[++x]==s){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

