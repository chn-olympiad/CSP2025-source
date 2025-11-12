#include<bits/stdc++.h>
using namespace std;
int n,m,obj,cnt=1;
int a[107],s[17][17];
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
	obj=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[cnt]==obj){
					cout<<i<<" "<<j;
					return 0;
				}
				s[i][j]=a[cnt++];
			} 
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[cnt]==obj){
					cout<<i<<" "<<j;
					return 0;
				}
				s[i][j]=a[cnt++];
			} 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
