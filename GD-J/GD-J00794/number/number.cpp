#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	cout<<endl;
	for(int i=9;i>=0;i--){
		while(a[i]){
			a[i]--;
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
