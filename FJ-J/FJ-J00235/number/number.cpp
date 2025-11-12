#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long b[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(long long i = 0;i < a.size();i++)	{
		if(a[i] - '0' >= 0 && a[i] - '0' <= 9){
			b[a[i] - '0']++;
		}
	}
	for(long long i = 9;i >= 0; --i){
		for(;b[i] > 0;){
			cout<<i;
			b[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
