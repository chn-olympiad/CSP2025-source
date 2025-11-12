#include<bits/stdc++.h>
using namespace std;
int a[1111111];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;int o=0;
	while(cin>>c){
		if(c=='0'){a[o]=0;o++;}
		else if(c=='1'){a[o]=1;o++;}
		else if(c=='2'){a[o]=2;o++;}
		else if(c=='3'){a[o]=3;o++;}
		else if(c=='4'){a[o]=4;o++;}
		else if(c=='5'){a[o]=5;o++;}
		else if(c=='6'){a[o]=6;o++;}
		else if(c=='7'){a[o]=7;o++;}
		else if(c=='8'){a[o]=8;o++;}
		else if(c=='9'){a[o]=9;o++;}
	}
	sort(a,a+o);
	for(int i=o-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
