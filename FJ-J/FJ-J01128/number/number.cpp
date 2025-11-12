#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,e=0;
	cin >> a;
	char c[10]={0,1,2,3,4,5,6,7,8,9},s[a],d[a];
	for(int i=0;i<b;i++)
		cin >> s[i];
	for(int i=0;i<b;i++)
		for(int j=0;j<9;j++)
			if(s[i]=c[j])
				d[i]=s[i];
	for(int x=0;x<a;x++){
		for(int i=0;i<a;i++){
			if(d[i]>e)
				e=d[i];}
		cout << e;
		e=0;}
	return 0;
}