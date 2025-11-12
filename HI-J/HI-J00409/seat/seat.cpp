#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],v[11][11],s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+n*m,cmp);
	int flag=0,len=0;
	for(int j=1;j<=m;j++){
		if(flag==0){
			for(int i=1;i<=n;i++){
				v[i][j]=a[len];
				if(v[i][j]==s){
					cout<<j<<' '<<i;
					return 0;
				}
				len++;
			}
			flag=1;
		}else{
			for(int i=n;i>0;i--){
				v[i][j]=a[len];
				if(v[i][j]==s){
					cout<<j<<' '<<i;
					return 0;
				}
				len++;
			}
			flag=0;
		}
	}
	return 0;
}
