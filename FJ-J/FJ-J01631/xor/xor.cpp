//xor.cpp
#include<iostream>
#include<vector>
using namespace std;
long long list[int(5e5+1)];
long long xorplus(long long j,long long i){
	long long num=list[j];
	for(int k=j+1;k<=i;k++){
		num=num^list[k];
	}
	return num;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,i,j,cnt=0;
	cin>>n>>k;
	for(i=0;i<n;i++){
		cin>>list[i];
	}
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(xorplus(i,j)==k){
				cnt++;
				i=j;
				break; 
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
