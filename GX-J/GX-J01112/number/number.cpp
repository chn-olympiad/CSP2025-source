#include <bits/stdc++.h>
using namespace std;
char a[90000];
int c=1,d=0;
int main()
{   freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[300]{0};
	cin>>a;
    for(int i=0;c!=0;i++){
		 d=a[i];
		if(d>='0'&&d<='9') s[d]++;
		c=a[i+1];
	}for(int i='9';i>='0';i--){
		for(int j=s[i];j>0;j--)
		printf("%d",i-48);
	}
	return 0;
}

