#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,t,p=1;
	cin>>n>>m>>c;
	for(int i=1;i<n*m;i++){
		cin>>t;
		if(t>c) 
			p++;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			p--;
			if(!p){
				cout<<i<<" ";
				if(i%2)
					cout<<j;
				else
					cout<<n-j+1;
				return 0;
			}
		}
	return 0;
}
