#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],cnt=0;
int cmp(int x,int y){
	return x>y;
}
bool f=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(f==0){
			for(int j=1;j<=n;j++){
				if(a[++cnt]==r){
					cout<<i<<" "<<j;
					break;
				}
			}
			f=1;
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[++cnt]==r){
					cout<<i<<" "<<j;
					break;
				}
			}
			f=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
