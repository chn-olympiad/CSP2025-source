#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	m=n*m;
	for(int i=1;i<=m;i++)cin>>a[i];
	b=a[1];sort(a,a+m+1);
	for(int i=1;i<=m;i++)if(a[i]==b)b=m-i+1;
	if(b%n==0){
		if((b/n)%2==1)cout<<b/n<<" "<<n;
		else cout<<b/n<<" "<<1;
	}else{
		if((b/n)%2==1)cout<<b/n+1<<" "<<n-(b%n)+1;
		else cout<<b/n+1<<" "<<b%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
