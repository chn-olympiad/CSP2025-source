#include<bits/stdc++.h>
using namespace std;
int n,s,a,m,p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>s;
		if(s>a){
			p++;
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((i-1)*n+j-1==p){
				cout<<i<<" ";
				if(i%2==1){
					cout<<j;
				}else{
					cout<<n-j+1;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
