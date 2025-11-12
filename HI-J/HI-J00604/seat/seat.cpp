#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],b[225][225],k=1;
bool cmp(int a,int b){
	return a>b; 
}
bool flag=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(flag==false){
			for(int j=1;j<=n;j++){
				b[j][i]=a[k];
				k++; 
			}
			flag=true;
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[k];
				k++;
			}
			flag=false;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(b[i][j]==sum) cout<<j<<' '<<i;
	return 0;
}
