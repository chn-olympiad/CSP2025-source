#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
	string n;
	cin>>n;
	int a[10005],p=0;
	for(int i = 0;i < n.size();i++){
		if(n[i]-'0' >= 0 and n[i]-'0' <= 9){
			a[p] = n[i]-'0';
			p++;
		}
	}
	sort(a,a+p);
	for(int i = p-1;i >=0;i--) cout<<a[i];
	return 0;
}
