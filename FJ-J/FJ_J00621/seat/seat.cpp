#include<bits/stdc++.h>
using namespace std;
int x[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int y,wu;
	cin>>n>>m;
	y=n*m;
	for(int i=0;i<y;i++){
		cin>>x[i];
	}
	wu=x[0];
	int d=0;
	for(int i=0;i<y;i++){
		if(x[i]>wu){
			d++;
		}
	}
	int a,b;
	a=d/n+1;
	b=d%n+1;
	if(a%2==1){
		cout<<a<<" "<<b<<endl;
	}
	if(a%2==0){
		cout<<a<<" "<<m-b+1<<endl;
	}
	return 0;
}