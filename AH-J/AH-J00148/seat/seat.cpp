#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10000],b[110][110];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s,k=0;
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
		for(int i=1;i<=n;i++){
		   if(i%2!=0){
			   for(int j=1;j<=m;j++){
				   k++;
				   b[i][j]=a[k];
			   }
		   }
	       if(i%2==0){
			   for(int j=m;j>=1;j--){
				   k++;
				   b[i][j]=a[k];
			   }
		   }		 
	  } 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j][i]==s) cout<<j<<" "<<i;
		}
	}
	cout<<"\n";
	return 0;
}

