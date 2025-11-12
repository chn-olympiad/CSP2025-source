#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	int a[1001];
	int n=0;
	for(int i=0;i<=s.size();i++){
		if(i>='0'&&i<='9'){
			a[i]=i;
		}
	}
	sort(a+1,a+1+n);
	cout<<a<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
