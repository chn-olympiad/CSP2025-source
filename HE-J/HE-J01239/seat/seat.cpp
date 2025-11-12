#include<bits/stdc++.h>
using namespace std;
long long a[15][15],b[110];
int self(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	long long sum=b[1];
	sort(b+1,b+n*m+1,self);
	int cmp=1,flag=1;
	for(int i=1;i<=n;i++){
		if(flag==1){
			for(int j=1;j<=m;j++){
				a[j][i]=b[cmp++];
				if(a[j][i]==sum){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			flag=0;
		}else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[cmp++];
				if(a[j][i]==sum){
					cout<<i<<' '<<j;
					return 0;
				}
			}
			flag=1;	
		}		
	}	
	return 0;
}
