#include<bits/stdc++.h>
using namespace std;
int main(){
	 
	 
	int n,m,a,h=1,l=1,k=0;
	cin>>n>>m;
	int b[n*m];
	cin>>a;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		h++;
		if(h>=n){
			l+1;
			while(h>1){
				h--;
			}
		}
		while(n*m){
			if(b[0]<b[i])[
				k=b[j];
				b[0]=b[i];
				b[0]=b[i];
				b[0+1];
		}
		if(a>=b[i]){
		cout<<l<<h;
		}
	}
	return 0;
}
