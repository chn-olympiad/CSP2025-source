#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[1000009],k=0,h=0;
	cin>>s;
	for(long long i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k);
	for(long long i=k;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}

