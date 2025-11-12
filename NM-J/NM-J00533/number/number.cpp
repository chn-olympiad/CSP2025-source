#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	int i = 0;
    freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	int x[10000], a = 0;
	string g, gg;
	cin >> g;
	for (int i = 0; i < g.length(); i++){
		if (g[i] <= 'z' && g[i] >= 'a'){
			continue;
		}
		else{
            x[a] = g[i] - '0';
            a++;
        }
	}
	for (int j = 1; j <= a ; j++){
        for (i = 1; i < a; i++){
            if(x[i] > x[i-1]){
                int t = x[i-1];
                x[i-1] = x[i];
                x[i] = t;
            }
        }
	}
	long long k = 0;
	for(int i = 0; i < a; i++){
        k += x[i]*pow(10, a-i-1);
	}
    cout << k;

    return 0;
}

