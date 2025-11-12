#include<bits/stdc++.h>
using namespace std;
bool cmt(int x,int y){
	return x>y;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);  
   int n,m;
   cin>>n>>m;
   int a[120];
   int y=n*m;
   for(int i=1;i<=y;i++){
   	
   		cin>>a[i];

   }
   int o=a[1];
   sort(a+1,a+y+1,cmt);
int k[105][105];
int sum=1;
for(int i=1;i<=m;i++){
	if(i%2==1){
		for(int j=1;j<=n;j++){
			
			k[j][i]=a[sum];
			sum++;
			if(k[j][i]==o){
				cout<<i<<" "<<j;
			}
		}
	}

	else{
		for(int j=m;j>=1;j--){
			
			k[j][i]=a[sum];
			sum++;
			if(k[j][i]==o){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
fclose(stdin);
fclose(stdout);
     return 0;
}

