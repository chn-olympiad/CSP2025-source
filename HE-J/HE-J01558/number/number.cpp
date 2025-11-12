#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n,f[1000000010];
	cin>>s;
	int x=0;
	int a=s.size();
	vector <int> b(a);
	char c[a];
	for(int i=0;i<a;i++){	c[i]=s[i];
		if(c[i]<='9'){
		b[i]=c[i];
	    f[i]=b[i];
		}
	}n=b.size();
	sort(f+1,f+n+1);
	while(n--){
	cout<<f[x];	x+=1;
	}
	}

