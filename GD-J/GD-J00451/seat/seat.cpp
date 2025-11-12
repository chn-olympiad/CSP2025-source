#include<bits/stdc++.h>
using namespace std;
int x,n,m,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int q=n*m;
	cin>>x;
	for(int i=2;i<=q;i++){
		int k;
		cin>>k;
		if(k>x){
			t++;
		}
	}
	q=t/m;
	cout<<q+1<<" ";
	if(q%2==0)
		cout<<t%m+1;
	else
		cout<<n-(t%m);
	return 0;
} 
