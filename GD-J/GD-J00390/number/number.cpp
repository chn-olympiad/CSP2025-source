#include<bits/stdc++.h>
using namespace std;
const int maxn =1000000;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int b=0;
	int c=1;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			if(s[i]=='0'){
			a[c]=0;
			b++;
			c++;
		    }
		    if(s[i]=='1'){
			a[c]=1;
			b++;
			c++;
		    }
		    if(s[i]=='2'){
			a[c]=2;
			b++;
			c++;
		    }
		    if(s[i]=='3'){
			a[c]=3;
			b++;
			c++;
		    }
		    if(s[i]=='4'){
			a[c]=4;
			b++;
			c++;
		    }
		    if(s[i]=='5'){
			a[c]=5;
			b++;
			c++;
		    }
		    if(s[i]=='6'){
			a[c]=6;
			b++;
			c++;
		    }
		    if(s[i]=='7'){
			a[c]=7;
			b++;
			c++;
		    }
		    if(s[i]=='8'){
			a[c]=8;
			b++;
			c++;
		    }
		    if(s[i]=='9'){
			a[c]=9;
			b++;
			c++;
		    }
		}
	}
    sort(a+1,a+b+1);
	for(int j=b;j>=1;j--){
	    cout<<a[j];
	}
    return 0;
}
