#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int a[1000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	char q[1000];
	int v=1;
	int k[2];
	for(int i=0;i<s.length();i++){
		q[i+1]=s[i];
		if(s[i]==0){
			v=0;
		}
		k[s[i]]++;
	}
	if(v==1){
		int h=1;
		for(int i=n,j=1;j<=m;i--,j++){
			h=h*i;
		}
		cout<<h%998244353;
		return 0;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
