#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a+=s[i];	
		}
	}
	for(int i=0;i<=a.size();i++){
		if(a[i]<=a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
