#include<bits/stdc++.h>
using namespace std;
string s;
long long n,q[310];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)q[s[i]]++;
	for(int j='9';j>='0';j--){
		for(int i=1;i<=q[j];i++) cout<<char(j);
	}
	return 0;
}

