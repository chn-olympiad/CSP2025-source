#include<bits/stdc++.h>
using namespace std;
int h[15][15],k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin.tie(0)->sync_with_stdio(false);
	cin>>a>>b;
	for(int i=1;i<=a;i++)for(int p=1;p<=b;p++){
	cin>>h[i][p];
	if(h[i][p]>h[1][1])++k;}
	if(k%a)
	{if((k/a+1)%2==1)
	cout<<k/a+1<<' '<<k%a;
	else
	cout<<k/a+1<<' '<<a-k%a+1;}
	else
	{if((k/a)%2==1)
	cout<<k/a<<' '<<a;
	else cout<<k/a<<' '<<1;}
	return 0;
}
