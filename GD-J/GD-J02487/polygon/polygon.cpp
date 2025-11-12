#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,san = 0,p = 0;
	cin>>n;
	if(n == 3){
		for(int i = 0;i < n;i++){
			cin>>a;
			p = max(p,a);
			san+= a;
		}
		if(p*2 >= san) cout<<0;
		else cout<<1;
	}
	return 0;
}
