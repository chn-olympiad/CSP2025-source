#include<bits/stdc++.h>
using namespace std;
int a[1000005],k;
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	while(cin>>s)
	{		
		if(s>='0'&&s<='9')
		{
			a[k]=s-'0',k++;
		}
	}
	sort(a,a+k+1);
	for(int i=k;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}

