#include<bits/stdc++.h>
using namespace std;
char s[1001];
long long s_[10000001];
int main(){
	freopen("numder.in","r",stdin);
	freopen("numder.out","w",stdout);
	bool f=0,zs=0;
	long long sum=0,zd,zx=10;
	for(int i=1;i<=9;i++){
		cin>>s[i];
		for(int j=0;j<=9;j++){
			if(int(s[i])==j){
				f=1;
				sum++;
				s_[i]=int(s[i]);
				break;
			}
		}
	}
	for(int i=2;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			if(s_[i]>zd&&zs==0){
				zd=s_[i];
				zs=1;
				cout<<zd;
				break;
			}
			else if(s_[i]<zx){
				zx=s_[i];
				break;
			}
		}
		cout<<zx;
	}
	return 0;
}
