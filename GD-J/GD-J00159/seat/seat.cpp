#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sc;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=1;j<=m;j++){
				if(a[i*m+j]==sc){
					cout<<i+1<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>0;j--){
				if(a[i*m+(m-j+1)]==sc){
					cout<<i+1<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
