#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

const int N=200005;

int n,q;
string sx[N],sy[N];
string tx,ty;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","r",stdin);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sx[i]>>sy[i];
	}
	while(q--){
		cin>>tx>>ty;
		int sum=0;
		for(int i=1;i<=n;i++){
			int j=tx.find(sx[i]);
			while(j!=-1){
				string ans=tx.substr(0,j);
				ans=ans+sy[i],ans=ans+tx.substr(j+sy[i].size(),tx.size()-ans.size());
				if(ans==ty)sum++;
				j=tx.find(sx[i],j+1);
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 
