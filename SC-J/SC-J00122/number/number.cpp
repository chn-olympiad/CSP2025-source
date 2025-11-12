#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int a[20]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int b=s[i]-'0';
			a[b]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=a[i];j>0;j--){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}