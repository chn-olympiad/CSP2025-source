#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

string str;
array<int,10>num; 

int main(int argc,char**argv) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>str;
	for(auto i:str) 
		if(i>='0'&&i<='9') num[(int)i-'0']++;
		
	for(int i=9;i>=0;--i) {
		for(int j=1;j<=num[i];++j) cout<<i;
	} 
	
	return 0;
}
