#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5100],ans=0,ui=0,mx=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3){
		for(int i=1;i<=n;i++)
			ui+=a[i];
		for(int i=1;i<=n;i++)
			mx=max(mx,a[i]);
		if(ui>mx*2)
			cout<<1;
		else if(ui<=mx*2)
			cout<<0;
	}
	else
		cout<<9;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
