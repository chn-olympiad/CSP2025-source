#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[401];
bool cmp(int a,int b){
	if(a>b){
		return true;
	}else if(a<b){
		return false;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i1=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[i1]=a[i][j];
			i1++;
		}
	}
	i1=1;
	int x=a[1][1];
	int y=n*m;
	sort(b+1,b+y+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=b[i1];
			i1++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==x){
				if(i%2==0){
					cout<<i<<" "<<m-j+1;
					return 0;
				}else{
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
