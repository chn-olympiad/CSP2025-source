#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k,a[10005],shu;
int t1,s1,t2;
void one(){
	cout<<n/2;
}
void two1(){
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			t1++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			s1++;
		}else{
			t1+=s1/2;
		}
	}
}
void two2(){
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			t2++;
		}
	}
}
void three(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int zhi=a[i];
			for(int c=i+1;c<=j;c++){
				zhi=a[c]^zhi;
			}
			if(zhi==k){
				shu++;
				i=j+1;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool tr=false,fal=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			tr=true;
		}
		if(a[i]>1){
			fal=true;
		}
	}
	if(tr==false){
		one();
		return 0;
	}
	else if(fal==false){
		if(k==0){
			two1();
			cout<<t1;
			return 0;
		}
		else if(k==1){
			two2();
			cout<<t2;
			return 0;
		}
	}
	else{
		three();
		cout<<shu;
		return 0;
	}
	return 0;
}