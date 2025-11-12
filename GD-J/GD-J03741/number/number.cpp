#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[10]={0};
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int p;
			p=s[i]-'0';
			a[p]+=1;
		}
	}
	string q;
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			q+=i+'0';
		}
	}
	cout<<q;	

	fclose(stdin);
	fclose(stdout);
}
