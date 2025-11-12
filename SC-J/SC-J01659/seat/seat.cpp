#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,x,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==k)x=i;
	}
	int t,p;
	t=x/n;
	p=x%n;
	if(t%2==0){
		t+=1;
		if(p==0)c=t-1,r=1;
		else c=t,r=p;
	}else{
		t+=1;	
		if(p==0)c=t,r=n;
		else c=t,r=n+1-p;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 