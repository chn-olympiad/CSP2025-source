#include<bits/stdc++.h>
using namespace std;
long long n,m,bcs,maxn,sum,l,h;
int ar[105],br[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>ar[i];
	}
	sum=ar[1];
	sort(ar+1,ar+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(ar[i]==sum){
			bcs=n*m-i+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(m*i>bcs){
			if(bcs%m!=0){
				h=bcs/m+1;
			}
			else{
				h=bcs/m;
			}
			l=m-(m*i-bcs);
			break;
		}
	}
	cout<<h<<' '<<l;
	return 0;
} 

