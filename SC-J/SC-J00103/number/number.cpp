#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[10];
	memset(a,sizeof(a),0);
	long long num=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(int(s[i])>=48&&int(s[i])<=57){
			a[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}