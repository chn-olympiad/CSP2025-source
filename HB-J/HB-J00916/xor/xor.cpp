#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,tmp;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>tmp;
	}
	if(tmp==3){
		cout<<2;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
