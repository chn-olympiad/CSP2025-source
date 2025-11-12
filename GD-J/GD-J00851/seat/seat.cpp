#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105]={0},cnt,i,j=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[a[i]]=1;
	}
	for(int i=100;i>=1;i--){
		if(b[i]==1) cnt++;
		if(i==a[1]) break;
	}
	for(i=1;i<=m;i++){
	    for(;j<=n;){
	    	cnt--;
	    	if(!cnt){
	    		cout<<i<<" "<<j<<endl;
				return 0;
			}
	    	else if(i%2==1 && j!=n) j++;
	    	else if(i%2==1 && j==n) break;
	    	else if(i%2==0 && j!=1) j--;
	    	else if(i%2==0 && j==1) break;
		}
	}
	return 0;
}
