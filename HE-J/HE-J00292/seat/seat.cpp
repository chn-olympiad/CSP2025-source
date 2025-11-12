#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=1,max=0,min=100;
	cin>>n>>m;
	int b[105];
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		if(b[i]>max)
			max=b[i];
		if(b[i]<min)
			min=b[i];
	}
	if(b[1]==max)
		cout<<1<<" "<<1;
	if(b[1]==min){
		if(m%2==0)
			cout<<m<<" "<<1;
		else{
			cout<<m<<" "<<n;
		}
	}
}
