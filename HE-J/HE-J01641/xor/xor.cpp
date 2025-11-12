#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m[1001],k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	int t[1001];
	for(int i=1;i<=n;i++){
		tong[m[i]]=m[i];
	}
	if(k==0){
		if(m[1]==m[2]){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
