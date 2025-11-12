#include <bits/stdc++.h>
using namespace std;
int number[100001];
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		int z=int(s[i]-'0');
		if(z>=0 && z<=9){
			n++;
			number[n]=s[i]-'0';
		}
	}
	sort(number+1,number+n+1);
	string b;
	for(int i=n;i>0;i--){
		b+=char(number[i]+'0');
	}
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 