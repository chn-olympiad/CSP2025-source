#include<bits/stdc++.h>
using namespace std;

char s[100000001], s2[100000001];
int l = 0, b[10000001];

int main(){
	scanf("%s", s + 1);
	l = strlen(s + 1);
	int a = 0;
	for (int i = 1; i <= l; i++){
	    	if (s[i] == '0'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '1'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '2'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '3'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '4'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '5'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '6'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '7'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '8'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }
	    	 if (s[i] == '9'){
	    	    ++a;
	    	    s2[a] = s[i];
	    	 }

    }
    for (int i = 1; i <= a; i++)
        b[i] = s2[i]-'a'+'A' - 16;
    sort(b + 1, b + a + 1);
    for (int i = a; i >= 1; i--)
        cout << b[i];
}
