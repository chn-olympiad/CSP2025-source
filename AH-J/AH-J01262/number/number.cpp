#include<bits/stdc++.h>
using namespace std;
long long a[100100],t[100100];
long long i,j,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long l=s.size();
	for(i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}else{
			a[i]=91;
		}
	}for(i=0;i<l;i++){
		if(a[i]!=91){
			t[a[i]]++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}

