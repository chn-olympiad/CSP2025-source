#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[200]={0};
int st[25][25]={0};

bool cmp(int ccc,int ddd){
	return ccc>ddd;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	int x=1;
	for(int j=1;j<=m;){
		
		for(int i=1;i<=n;i++){
			st[i][j]=a[x];
			x++;
		}
		j++;
		for(int i=n;i>=1;i--){
			st[i][j]=a[x];
			x++;
		}
		j++;
		
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(st[i][j]==num){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}

