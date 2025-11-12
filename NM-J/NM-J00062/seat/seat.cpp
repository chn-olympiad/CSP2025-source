#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,a;
	cin>>n>>m;
	long long b[n*m],c[n*m];
	for(int k=0;k<m*n;k++){
		cin>>c[k];
	}
	a=c[0];
	sort(c,c+n*m);
	for(int i=0;i<n*m;i++){
		b[i]=c[n*m-1-i];
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(b[i*n+j]==a){
				cout<<i+1<<" ";
				if(i%2==0){
					cout<<j+1;
				}
				else{
					cout<<n-j;
				}
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
