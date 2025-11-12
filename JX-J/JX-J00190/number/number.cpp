#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char a[1000005]={};
	long long sizeS=s.size();
	long long sizeA=0;
	for(long long i=0;i<sizeS;i++){
		if(s[i]>=48&&s[i]<=57){
			a[sizeA]=s[i];
			sizeA++;
		}
	}
	for(long long i=0;i<sizeA;i++){
		for(long long j=i;j<sizeA;j++){
			if(a[i]<a[j]){
				long long ai=a[i];
				a[i]=a[j];
				a[j]=ai;
			}
		}
	}
	string cnt="";
	for(long long i=0;i<sizeA;i++) cnt+=a[i];
	cout<<cnt<<endl;
	return 0;
}
