#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>k;
	cout<<rand()%n+k+3;
	return 0;
} 
