#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int aa,num=0;
	cin>>aa;
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		if(b>aa)num++;
	}
	int a=num/m+1,b=num%m;
	if(a%2==0)b=m-b;
	else b++;
	cout<<a<<" "<<b<<'\n';
	return 0;
}
