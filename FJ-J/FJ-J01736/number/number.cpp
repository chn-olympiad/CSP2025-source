#include<bits/stdc++.h>
using namespace std;
char c; int t[16];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    while(((c = getchar()) >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
    	if(c >= '0' && c <= '9') t[c - '0']++;
    for(int i = 9; i >= 0; i--) while(t[i]--) putchar(i + 48);
	return 0;
}

