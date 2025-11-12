#include <bits/stdc++.h>
using namespace std;

string s;
int a[1005];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int c =0;
    long double l = s.size();
    for(int i =0;i<l;i++){
    	if(s[i]=='0'){
    		a[c] = 0;
    		c++;
		}else if(s[i]=='1'){
    		a[c] = 1;
    		c++;
		}else if(s[i]=='2'){
    		a[c] = 2;
    		c++;
		}else if(s[i]=='3'){
    		a[c] = 3;
    		c++;
		}else if(s[i]=='4'){
    		a[c] = 4;
    		c++;
		}else if(s[i]=='5'){
    		a[c] = 5;
    		c++;
		}else if(s[i]=='6'){
    		a[c] = 6;
    		c++;
		}else if(s[i]=='7'){
    		a[c] = 7;
    		c++;
		}else if(s[i]=='8'){
    		a[c] = 8;
    		c++;
		}else if(s[i]=='9'){
    		a[c] = 9;
    		c++;
		}
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		cout << a[i];
	}
    return 0;
}

