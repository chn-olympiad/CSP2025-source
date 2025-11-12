#include<bits/stdc++.h>
using namespace std;
int a[105];	
int b[13][13];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	cnt=a[0];
	sort(a,a+n*m);
	int j=0;
	j=n*m-1;
	int q=0,p=0;
	bool s=0;
	for(int y=1;y<=m;y++){
		if(y%2==1){
			for(int x=1;x<=n;x++){
				b[x][y]=a[j];
				if(a[j]==cnt){
					q=y;
					p=x;
					s=1;
					break;
				}
				j-=1;
			}
		}else{
			for(int x=n;x>=1;x--){
				b[x][y]=a[j];
				if(a[j]==cnt){
					q=y;
					p=x;
					s=1;
					break;
				}
				j-=1;
			}
		}
		if(s==1){
			break;
		}
	}
	cout<<q<<" "<<p;
	fclose(stdin);
	fclose(stdout);
}
