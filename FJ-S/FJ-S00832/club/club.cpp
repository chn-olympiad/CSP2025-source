#include<bits/stdc++.h>
using namespace std;
int t,n,a1,b1,c1,maxgood=0;
struct node{
	int x,number; 
}a[10005][10005];
int main(){
	freopen("club.in ","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int sum1;
		int line=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i].x;
				a[j][i].number=j;
			}
		}
		for(int i=1;i<=n;i++){
			int max1=0;
			for(int j=1;j<=3;j++){
				max1=max(max1,a[i][j].x);
			}
			sum1+=max1;
		}
		cout<<sum1;
	}
	return 0;
}
