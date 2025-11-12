#include <bits/stdc++.h>
using namespace std;
char a[1000005];
char b[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//int n;
	//cin >> n;
	int bj1=1, bj2=1;
	while(cin >> a[bj1]/*&&bj1<=n*/){
		if(a[bj1]>='0'&&a[bj1]<='9'){
			b[bj2]=a[bj1];
			bj2++;
		}
		bj1++;
	}
	for(int i=1;i<=bj2-1;i++)
	for(int j=i+1;j<=bj2;j++)
	{
		if(int(b[i])<=int(b[j]))
		swap(b[i],b[j]);
	}
	for(int i=1;i<=bj2;i++)
	cout << b[i];
	return 0;
}