#include<bits/stdc++.h>
using namespace std;
int n,m,cj[500],top=0,r,s;
int xsqz(int a,int b){
	if(a%b) return a%b;
	else return b;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>cj[++top];
		}
	}
	r=cj[1];
	sort(cj+1,cj+1+top);
	for(int i=top;i>=1;i--)
	{
		if(cj[i]==r) s=top-i+1;
	}
	int ans=(s-1)/m+1;
	if(ans%2==0) cout<<ans<<" "<<n-xsqz(s,ans)+1;
	else cout<<ans<<" "<<s-(ans-1)*n;
	return 0;
}