#include<bits/stdc++.h>
using namespace std;
long long b[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	long long c=b[1];
	sort(b+1,b+n*m+1);
	long long i=1,j=1,k=n*m;
	while(k>=1){
		if(b[k]==c){
			cout<<j<<" "<<i;
			return 0;
		}
		k--;
		if(j%2==1){
			if(i==n){
				j++;
			}else{
				i++;
			}
		}else{
			if(i==1){
				j++;
			}else{
				i--;
			}
		}
	}
	return 0;
}
