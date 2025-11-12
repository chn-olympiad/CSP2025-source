#include<bits/c++.h>
using namespace std;
freopen(stdin,"r",number.in);
freout(stdout,"w",number.out);
long long li(long long n,long long x){
	x=n;
	while(n-1!=0){
		x=x*(n-1);
		n-=1;
		}
	return x;
int main(){
	string s;
	long long n[100000000],m=0,j=0;
	cin>>s;
	for(int i=0;i<s;i++){
	if(s[i]<=9&&s[i]>=0){
	m++;
	n[j]=s[i];
	j++;
	}
	}
	if(m==0){
		cout<<"NO";
	}
	else{
	long long c[100000000],v;
	for(int i=1;i<=li(j);i++){
		int a,k=0;
		for(v=0;v<=li(j-1);v++){
		while(k+1!=j){
		a=n[k]*10*j+n[k+1]*10*j-1;
		k++;
		}
		c[v]=a;
	}
	}
	long long max=-1;
	for(int i=0;i<=v;i++){
		if(c[v]>max){
		   max=c[v];
		}
	}
	cout<<max;
}
}
