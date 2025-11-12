#include <bits/stdc++.h>
using namespace std;
long long n,m,u,t,p;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>u;
	t=1;
	for(int i=1;i<=n*m-1;i++){
		cin>>p;
		if(p>u) t++;
	}
	int lie=t/n;
	if(t%n!=0) lie++;
	if(lie%2==1){
		cout<<lie<<' ';
		if(t%n==0) cout<<n;
		else cout<<t%n;
	}
	else{
		cout<<lie<<' ';
		if(t%n==0) cout<<1;
		else cout<<n+1-t%n;
	}
	//cout<<endl<<lie<<' '<<t;
	
	
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
