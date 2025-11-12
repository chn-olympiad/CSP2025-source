#include<bits/stdc++.h>
using namespace std;
int m,n,a[105],k,g;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>k;
	a[k]=k;
	for(int i=2;i<=m*n;i++){
		cin>>g;
		a[g]=g;
	}
	for(int v=100,i=1,j=1;v>0;v--){
		if(a[v]!=0){
			if(v==k){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			if(i%2==1){
				if(j+1>n)i++;
				else j++;
			}else{
				if(j-1<1)i++;
				else j--;
			}
		}
	}
}