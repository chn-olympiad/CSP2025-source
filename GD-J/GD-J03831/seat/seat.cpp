#include<bits/stdc++.h>
using namespace std;
int a[105][105],n,m,op[100005],x,y,k,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			cin>>op[k];
			if(i==1&&j==1)r=op[k];
		}
	}
	sort(op+1,op+k+1);
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				a[j][i]=op[k];
				if(op[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
				
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[j][i]=op[k];
				if(op[k]==r){
					cout<<i<<" "<<j;
					return 0;
				}
				k--;
				
			} 
		}
	}
	return 0;
}
