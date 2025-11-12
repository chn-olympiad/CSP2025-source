#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],sum=0,num=1,num1=1;
void aaa(int l,int r){
	int l1=l;
	int r1=r;
	int mid=(a[l]+a[r])/2;
	while(l<=r){
		while(a[l]<mid) l++;
		while(a[r]>mid) r--;
		if(l<=r){
			swap(a[l],a[r]);
			l++;
			r--;
		}
	}
	if(l1<r) aaa(l1,r);
	if(r1>l) aaa(l,r1);
}
long long pan(int nm,int p,int s[]){
	s[p]=0;
	int ss[100000],top=1;
	for(int i=1;i<=nm+1;i++){
		if(s[i]!=0){
			ss[top]=s[i];
			top++;
		}
	}
	long long sm=0;
	long long sm1=0;
	if(nm==3){
		if(ss[1]>=ss[2]+ss[3]) return 0;
		else return 1;
	}
	else{
		for(int i=1;i<=nm;i++){
			sm+=pan(nm-1,i,ss);
			sm%=998244353;
		}
		for(int i=1;i<=nm;i++){
			sm1+=ss[i];
		}
		sm%=998244353;
		if(sm1>ss[1]*2){
			sm++;
			sm%=998244353;
			return sm;
		}
		else return sm;
	}
}
int main(){
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin>>n;
	for(int i=1;i<=n;i++) fin>>a[i];
	if(n==3){
		if(a[1]<a[2]) swap(a[1],a[2]);
		if(a[1]<a[3]) swap(a[1],a[3]);
		if(a[1]>=a[2]+a[3]) fout<<0;
		else fout<<1;
	}
	int t=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1) t=0;
	}
	if(t==1){
		for(int j=1;j<=n;j++){
				num1*=j;
				num1%=998244353;
			}
		for(int i=3;i<=n;i++){
			num=1;
			for(int j=1;j<=i;j++){
				num*=j;
				num%=998244353;
			}
			for(int j=1;j<=n-i;j++){
				num*=j;
				num%=998244353;
			}
			sum+=(num1/num)%998244353;
		}
		fout<<sum%998244353;
	}
	else{
		aaa(1,n);
		int s[100000];
		for(int i=1;i<=n;i++) s[i]=a[i];
		fout<<pan(n,0,s)%998244353;
	}
	return 0;
}
