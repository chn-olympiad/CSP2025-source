#include <bits/stdc++.h>
using namespace std;
int t,n,i,j;
int x,y,k,p;
int y1=0,y2=0,y3;
long long a[1005][1005],b[10005],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cout<<endl;
	for(x=1;x<=t;x++){
		cin>>n;
		cout<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				cin>>a[i][j];
				cout<<" ";
			}
			cout<<endl;
		}
		ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				if(a[i][j]<=a[i+1][j]){
					p=a[i][j];
					a[i][j]=a[i+1][j];
					a[i+1][j]=p;
				}
				if(a[i][j]<a[i][j+1]){
					p=a[i][j];
					a[i][j]=a[i][j+1];
					a[i][j+1]=p;
				} 
						
			}
		}
		for(i=1;i<=n/2;i++){
			for(j=1;j<=3;j++){
				b[i+j]=a[i][j];
			}
		}
		y=n*3;
		for(i=1;i<=y;i++){
			if(b[i]<b[i+1]){
				k=b[i];
				b[i]=b[i+1];
				b[i+1]=k;
			}
		} 
		for(i=1;i<=n;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
