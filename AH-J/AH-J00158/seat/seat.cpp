#include<bits/stdc++.h>
using namespace std;
int t[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	int a;
	cin>>n>>m;
	num=n*m;a=0;
	for(int i=0;i<num;i++)
		scanf("%d",&t[i]);
	for(int i=1;i<num;i++)
		if (t[i]>t[0]) a++;
	cout<<1+a/m<<" ";
	if ((a/n)%2==0) cout<<a%m+1;
	else cout<<m-a%m;
	return 0;
}
