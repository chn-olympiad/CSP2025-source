#include<bits/stdc++.h>
using namespace std;
char a[1000010],s[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int i=0,j=-1;
	while(i<=sizeof(a))
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			j++;
			s[j]=a[i];
		}
		i++;
	}
	sort(s,s+j,cmp);
	cout<<s;
	return 0;
}
