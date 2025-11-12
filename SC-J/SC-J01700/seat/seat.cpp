#include <bits/stdc++.h>
using namespace std;
int a[110];
int mp[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;//n为行数，m为列数 
	cin>>n>>m;
	int k=m*n;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	} 
	int x=a[1];
	sort(a+1,a+1+k,cmp);
	int ansx,ansy;
	for(int i=1;i<=m;i++){
		//int end,d,sta;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[(i-1)*n+j];
				if(mp[j][i]==x) ansx=i,ansy=j; 	
			}	
		}
		else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[i*n+1-j];
				if(mp[j][i]==x) ansx=i,ansy=j; 	
			}
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}

