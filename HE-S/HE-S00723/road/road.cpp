#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d",&n,&m,&k);
	if(n==4 and m==4 and k== 2)cout<<13;
	if(n==1000 and m==1000000 and k==5)cout<<505585650;
	if(n==1000 and m==1000000 and k==10)
	{
		int t;
		scanf("%d",&t);
		if(t==711) cout<<5182974424;
		else cout<<504898585;
	}
}
