#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long b[10];
	for(int i=0;i<10;i++)b[i]=0;
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[a[i]-'0']++;
		}
	}
	int k=1;
	for(int i=9;i>=0;i--){
		if(!i&&k)cout<<0;
		else{
			if(b[i]!=0)k=0;
			for(int j=1;j<=b[i];j++)cout<<i;
		}
	}
	return 0;
}