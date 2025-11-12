#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,sum=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a){
			sum++;
		}
	}
	int q=1,w=0;
	while(sum--){
		if(w==n){
			w=0;
			q++;
		}
		w++;
	}
	if(q%2==1)
	cout<<q<<" "<<w;
	else
	cout<<q<<" "<<n-w+1;
}
