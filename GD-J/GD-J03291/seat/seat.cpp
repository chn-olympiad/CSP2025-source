#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,num=1;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		int a;
		cin>>a;
		if(a>x)num++;
	}
	int a,b;
	b=(num-1)/n+1;
	if(b%2)a=(num-1)%n+1;
	else a=n-(num-1)%n;
	cout<<b<<' '<<a<<endl;
	fclose(stdin);
	fclose(stdout);
	//system("fc seat.out ans.out");
	return 0;
}
