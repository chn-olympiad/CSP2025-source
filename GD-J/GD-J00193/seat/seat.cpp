#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int i;
	for(i=1;i<=n*m;i++){
		if(a[i]==t)break;
	}
	cout<<ceil(i*1.0/m)<<" ";
	if((i/m)%2){
		if(i%m==0)cout<<m;
		else cout<<m-(i%m);
	}else{
		if(i%m==0)cout<<1;
		else cout<<i%m;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
