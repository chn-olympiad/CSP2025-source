#include<bits/stdc++.h>
using namespace std;
int a[1005],num;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	int now=0,ans=1,f=1;
	for(int i=1;i<=n*m;i++){
		if(f==1)
			now++;
		else
			now--;
		if(now>n)
			now=n,ans++,f=!f;
		else if(now<1)
			now=1,ans++,f=!f;
		if(a[i]==num)
			break;
	}
	cout<<ans<<" "<<now;
	return 0;
}
