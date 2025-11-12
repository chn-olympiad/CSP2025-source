#include <bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	char a[1000000000];
	int b=1;
	int c[1000000000];
	for(int i=0;i<s.length();i++){
		if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
			a[b] = s[i];
			b++;
		}
	}
	for(int i=1;i<=b-1;i++){
		c[i] = a[i] - '0';
	}
	int h;
    for(int i=1;i<=b-1;i++){
		for(int j=1;j<=b-2;j++){
		    if(c[j]<c[j+1]){
		    	h = c[j+1];
		    	c[j+1] = c[j];
		    	c[j] = h;
			}
	    }
    }
	for(int i=1;i<=b-1;i++){
	    cout << c[i];
	}

    
	fclose(stdin);
	fclose(stdout);
	return 0;
}
