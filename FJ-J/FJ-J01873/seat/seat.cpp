#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[110],bl,se;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	bl=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(bl==a[i])	se=i;
	}
	if((se/n)%2==0){
		cout<<ceil(((se+n/2)*1.0)/n)<<' ';
		if(se%n!=0||se==0)	cout<<m-(se)%n-1;
		else	cout<<m-n+1;
	}
	else{
		cout<<ceil(((se+n/2))/n)<<' ';
		if(se%n!=0||se==0)	cout<<(se)%n+1;
		else cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
