#include<cstdio>
#include<iostream>
using namespace std;
char a[1000001];
char dd[1000001];
int main(){
	int k=1;
	string s;
	cin>>s;
//	freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	for(int i=1;i<=1000000;i++){
		dd[i]=s[i];
	}
	for(int i=1;i<=1000000;i++){
		if(dd[i]<=9 and dd[i]>=0){
			a[k]=dd[i];
			k+=1;
		}
	}
	k-=1;
	int m=k-1;
	while(m>0){
		for(int i=1;i<=m;i++){
			if(a[i]<a[i+1]){
				int t=a[i+1];
				a[i+1]=a[i];
				a[i]=t;
			}
		}
		m--;
	}
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
