#include <bits/stdc++.h>
using namespace std;
int n,m,r=1,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>num;
	for(int i=1;i<n*m;++i){
		int f;
		cin>>f;
		if(f>num)
			++r;
	}
	cout<<ceil(r*1.0/n)<<' ';
	int f=ceil(r*1.0/n);
	if(f%2==1)
		cout<<r-(f-1)*n<<endl;
	else
		cout<<n+1+(f-1)*n-r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
