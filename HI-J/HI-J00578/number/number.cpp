#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i=0,n[1000005],m=0;
	while(s[i]!=0){
		if(s[i]=='0'){
			n[m]=0;
			m++;
		}
		if(s[i]=='1'){
			n[m]=1;
			m++;
		}
		if(s[i]=='2'){
			n[m]=2;
			m++;
		}if(s[i]=='3'){
			n[m]=3;
			m++;
		}if(s[i]=='4'){
			n[m]=4;
			m++;
		}if(s[i]=='5'){
			n[m]=5;
			m++;
		}if(s[i]=='6'){
			n[m]=6;
			m++;
		}if(s[i]=='7'){
			n[m]=7;
			m++;
		}if(s[i]=='8'){
			n[m]=8;
			m++;
		}if(s[i]=='9'){
			n[m]=9;
			m++;
		}
		i++;
	}
	sort(n,n+m);
	for(int j=m-1;j>=0;j--){
		cout<<n[j];
	}
	return 0;
}

