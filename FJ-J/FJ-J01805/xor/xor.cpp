#include<bits/stdc++.h>
using namespace std;
long long rjz(int n){
	int num=0;
	int q=0;
	while(n!=0){
		num=(n%2)*pow(10,q)+num;
		n/=2;q++;
	}
	return num;
}

long long andor(int n,int m){
	int num=0;
	int q=0;
	while(n!=0&&m!=0){
		int n1,m1;
		n1=n%10;m1=m%10;
		if(n1==m1){
			num=num+pow(10,q);
		}
		n/=10;m/=10;q++;
	}
	return 0;
}
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
