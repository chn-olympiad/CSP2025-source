#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int bj1=0,bj2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			bj1=1;
		}else if(a[i]!=0){
			bj2=1;
		}
	}
	if(k==0&&bj2==0){//特殊性质A 
		cout<<n/2;
	}else if(bj1==0&&k<=1){//特殊性质B 
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				s++;
			}
		}
		cout<<s;
	} 
	
	
	return 0;
} 
/*
1=拿下！

注意freopen注释 
3.30!
好难QAQ 根本就没看懂
方法：一个测试点一个测试点拿分！时间还够！>40分就第四题！ 
*/