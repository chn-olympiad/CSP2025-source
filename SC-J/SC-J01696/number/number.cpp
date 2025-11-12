#include<bits/stdc++.h> 
using namespace std;
string a[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && s[i]<='9'){
			a[b]=s[i];
			b+=1;
		}
	}
	string n,m;
	sort(a,a+b);
	for(int i=0;i<b;i++){
		n+=a[i];
	}
	for(int i=n.size()-1;i>=0;i--){
		m+=n[i];
	}
	cout<<m<<endl;

	
	
	return 0;
}