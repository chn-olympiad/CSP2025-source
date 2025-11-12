#include <bits/stdc++.h>
using namespace std;


int a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	string x="I don't know what is it.Can you help me?";
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1 && n%2==0)
		{
			x="fuck.";
		}
		else if(a[i]!=1 && n%2!=0) x="what?What are you saying?";
	}
	cout << x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
