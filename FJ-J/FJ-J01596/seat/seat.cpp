#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b=1,c;
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++){
		cin>>c;
		if(c>a){
			b++;
		}
	}
	int q=ceil(b*1.0/n);
	cout<<q<<" ";
	swap(n,m); 
	if(q%2==0){
		cout<<m+1-(b%m!=0?b%m:m);
	}
	else{
		cout<<(b%m!=0?b%m:m);
	}
	return 0;
} 
