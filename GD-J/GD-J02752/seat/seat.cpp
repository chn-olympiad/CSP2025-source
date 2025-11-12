#include<bits/stdc++.h>
using namespace std;
int a[205];
int ans[105][105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++k];
		}
	}
	int tmp=a[1];
	int ii;
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==tmp){
			ii=i;
			break;
		} 
	}
	int i=1,j=1,f=0;
	int kk=1;
	while(kk<=n*m){
		ans[i][j]=a[kk];
		kk++; 
		if(i==n && f==0){
			j++,f=1;
		}
		else if(i==1 && f==1){
			j++,f=0;
		}
		else{
			if(f==0) i++;
		else if(f==1) i--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==tmp){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}

