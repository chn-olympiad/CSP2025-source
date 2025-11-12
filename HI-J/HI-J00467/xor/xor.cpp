#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long num=0;
	if(n==1){
		cout<<"1";
		return 0;
	}
	if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				num++;
			}
		}
		if(num%2==0){
			cout<<num-1;
		}else{
			cout<<num;
		}
		return 0;
	}
	if(k==0){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				num++;
			}
		}
		if(num%2==0){
			cout<<num;
		}else{
			cout<<num-1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
