#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010]={},c,b,an,am;
bool cmp(int pre,int nxt){
	return pre>nxt;
}
int main(){
  	freopen("seat.in","r",stdin);
  	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	c=a[1];sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(c==a[i]){b=i;break;}
	}
	an=(b-1)/n+1;
	am=b-(an-1)*n;
	if(an%2==0)am=n-am+1;
	cout<<an<<" "<<am;
	return 0;
}
