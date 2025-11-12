#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000005],sum=0;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			n[i]=s[i]-'0';
			sum++;
		}
	}
	sort(n,n+s.length(),cmp);
	if(n[0]==0){
		cout << 0;
	}else{
		for(int i=0;i<sum;i++){
			cout << n[i];
		}
	}
	return 0;
}

