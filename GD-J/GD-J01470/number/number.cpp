#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[(int)(s[i]-'0')]++;
			
		}
	}
	for(int i=9;i>=1;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
