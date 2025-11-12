#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,ming,a=0,q=0;
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h[n+m],hi[n][m];
	for(int i=0;i<n+m;i++){
		cin>>h[i];
	}
	ming=h[0];
	for(int i=0;i<n+m;i++){
		for(int j=i;j<n+m;j++){
			if(h[i]<h[j]){
				a=h[i];
				h[i]=h[j];
				h[j]=a;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			hi[j][i]=h[j];
			if(hi[j][i]==ming){
				cout<<i+1<<" "<<j+1;
				q=1;
				break;
			}
		}
		if(q==1){
			break;
		}
	}
	
	return 0;
}