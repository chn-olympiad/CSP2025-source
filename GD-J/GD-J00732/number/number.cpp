#include<bits/stdc++.h>
using namespace std;
char a[1000010];
char b[1000010];
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(b,1000010);
	long long l=strlen(b);
	for(long long i=0;i<l;i++){
		if(b[i]+0<=57&&b[i]+0>=48){
			long long k=b[i]-48;
			a[k]++;
		}
	}
	for(long long i=9;i>=0;i--){
		for(long long j=0;j<a[i];j++ ){
			cout<<i;
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

