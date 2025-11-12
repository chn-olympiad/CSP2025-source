#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,b;
	cin>>s;
	int a=sizeof(s),c=sizeof(b);
	
	for(int i=0;i<a;i++){
			if(s[i]>='1'&&s[i]<='9')
			{
				b[i]=s[i];
				
			}
	
	}
	for(int i=0;i<c;i++){
		for(int j=i;j<c;j++)
		if(b[i]<b[j]){
			int t=b[i];
			b[i]=b[j];
			b[j]=t;
		}
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}	
	
	return 0;
}

