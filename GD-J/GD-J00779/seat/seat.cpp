#include<bits/stdc++.h>
using namespace std;
int n,m,sx;
int a=1; //ÅÅÃû 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>sx;
	for(int i=1;i<n*m;++i){
		int x;
		cin>>x;
		if(x>sx) ++a;
	}
	if(((a-1)/n)%2==1){
		cout<<(a-1)/n+1<<' '<<n-((a-1)%n);
	}
	else{
		cout<<(a-1)/n+1<<' '<<(a-1)%n+1;
	}
	return 0;
}
