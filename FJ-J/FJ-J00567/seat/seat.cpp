#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int b[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r1=0,x=1,y=1;
	cin>>n>>m;
	for(int k=1;k<=n*m;k++){
		cin>>b[k];
		if(k==1) r1=b[k];
	}
	sort(b+1,b+n*m+1,cmp);
	bool flag=true;
	for(int i=1;i<=n*m;){
		for(x=1;x<=n;x++){
			if(flag==true){
				a[x][y]=b[i];
				i++;
				if(a[x][y]==r1){
					cout<<y<<" "<<x;
					return 0;
				}
			}
		}
		++y;
		flag=!flag;
		for(x=n;x>=1;x--){
			if(flag==false){
				a[x][y]=b[i];
				i++;
			}
			if(a[x][y]==r1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		++y;
		flag=!flag;
	}
	return 0;
} 
