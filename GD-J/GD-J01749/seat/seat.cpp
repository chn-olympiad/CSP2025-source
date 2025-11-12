#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],k;
int mp[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int sc=a[1];//小R的分数
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[++k];
			}	
		}
		else{
			for(int j=n;j>=1;j--)mp[j][i]=a[++k];
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)if(mp[j][i]==sc)cout<<i<<" "<<j;
	return 0;
} 
