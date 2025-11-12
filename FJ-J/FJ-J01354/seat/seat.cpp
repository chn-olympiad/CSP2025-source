#include<bits/stdc++.h>
using namespace std;
int n,m,pos,a,num=1;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1) pos=a;
		else if(a>pos) num++;
	}cout<<(num+n-1)/n<<" ";
	int u=(num-1)%n+1;
	if((num+n-1)/n%2==1) cout<<u;
	else cout<<m-u+1;
	return 0;
}
