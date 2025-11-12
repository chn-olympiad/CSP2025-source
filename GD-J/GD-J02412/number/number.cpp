//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <stdio.h> 
using namespace std;
string a;
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	len = a.size();
	int m[len + 5];
	int j = 1;
	for(int i = 0;i < len;i++)
	{
		//cout << a[i] << endl;
		if('1' <= a[i] <= '9'){
			m[j] = a[i] - '0';
			j++;
		}
	}
	j--;	
	for(int w = 9;w >= 0;w--){
		for(int i = 1;i <= j;i++){
			if(m[i] == w){
				cout << w;
			}
		}
	}
}
