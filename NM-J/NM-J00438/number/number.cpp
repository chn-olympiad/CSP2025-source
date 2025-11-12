#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string std;
	cin>>std;
	long n[10]={};
	long long dex=0;
	for(long long i=0;i<std.size();i++){
		if(std[i]>='0' && std[i]<='9'){
			long t=std[i]-'0';
			n[t]++;
			dex++;
		}
	}
	
	for(long i=9;i>=0;i--){
		for(long j=0;j<n[i];j++){
			printf("%ld",i);
		
		}
	}
	
	return 0;
}

