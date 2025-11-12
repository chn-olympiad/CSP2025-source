#include<bits/stdc++.h>
using namespace std;
char a[1000011];
int a1[1000001],b,c=0,s=0,x;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(a[c]>=1&&a[c]<=150){
		if(a[c]>=48&&a[c]<=57){
			s++;
			a1[s]=a[c]-48;
		}
		c++;
	}
	sort(a1+1,a1+s+1);
	for(int i=s;i>=1;i--){
		cout<<a1[i];
	}
	return 0;
}
