#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
string s;
long long arr[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
        if(s[i]>='0' && s[i]<='9'){
            arr[s[i]-'0']++;
        }
	}
	for(int i=9;i>=0;i--){
        for(int j=1;j<=arr[i];j++){
            cout<<i;
        }
	}
	return 0;
}
