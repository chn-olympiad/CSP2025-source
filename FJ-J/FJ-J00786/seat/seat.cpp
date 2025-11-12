#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1000][1000];
	int b[1000001];
	int n,m,c,r;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=m-1;j++){
			cin>>b[i*j];
			b[i*j]=max(b[i*j],b[i*j-i]);
			if(i*j%n!=0){
				if(m%2=0){
					c=n-i*j%n;
				}
				else{
					c=i*j%n;
				}
			}
			else{
				c=i*j/n;
				if(m%2=0){
					r=1;
				}
				else{
					r=n;
				}
			}
			b[1]=a[r][c];
		}
	}
	cout<<c<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
