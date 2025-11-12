#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,j=0;
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	j=a[1];
	sort(a,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(j==a[i]&&n==1){
				cout<<"1 "<<i;
		}else if(j==a[i]&&m==1){
			cout<<i<<" 1";
		}
	} 
	return 0;
}

