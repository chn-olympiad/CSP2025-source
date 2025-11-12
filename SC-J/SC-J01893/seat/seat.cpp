#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ch[101][101],k=1,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=1;
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2!=0){
			for(int i=1;i<=n;i++){
			    ch[i][j]=a[k];
			    k++;
		    }
		}
		else{
			for(int i=n;i>=1;i--){
			    ch[i][j]=a[k];
			    k++;
		    }
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[i][j]==r){
				x=j;
				y=i;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}