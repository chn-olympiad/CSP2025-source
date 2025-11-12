#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],rs,nn;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	//ovo qwq awa
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[++nn];
			if(nn==1)rs=a[nn];
		}
	sort(a+1,a+1+nn,greater<int>());
	int pos;
	for(int i=1;i<=nn;i++)
		if(a[i]==rs)
		{
			pos=i;
			break;
		}
	int zu;
	if(pos%(2*n)==0)zu=pos/2/n;
	else zu=pos/2/n+1;
	int left=pos-(zu-1)*2*n;
	if(left<=n)cout<<(zu-1)*2+1<<" "<<left;
	else cout<<zu*2<<" "<<2*n-left+1;
	return 0;
}
