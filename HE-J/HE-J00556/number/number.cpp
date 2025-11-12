#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
char a[100010];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin >> s;
    long long n = 0;
    for(int i = 0; i <= s.size(); i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[n] = s[i];
            n ++;
        }
    }
    for(int i = 1; i <= n * n * n * n; i ++){
    	int num = 0;
    	for(int j = 0; j <= n; j ++){
    		if(a[j] < a[j + 1]){
    			swap(a[j],a[j + 1]);
    			num ++;
			}
		}
		if(num == 0){
			break;
		}
	}
    for(int i = 0; i <= n; i ++){
        cout << a[i];
    }
    return 0;
}
