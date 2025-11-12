#include<bits/stdc++.h>
using namespace std;
int n,m,a[10004],ai=0,b[105][105],l=1;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ai=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[i][j]=a[l];
				l++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				b[i][j]=a[l];
				l++;
			}
		}

	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ai==b[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}	
}
