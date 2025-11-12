#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
string s;
long long a[10],n,m;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n%2==0&&m==0){
		cout<<n/2;
	}
	else{
		if(m==1){
			cout<<n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
