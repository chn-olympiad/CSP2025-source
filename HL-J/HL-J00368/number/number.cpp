#include<bits/stdc++.h>
using namespace std;
string s;
string b;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s+=a[i];
		}
	}
	sort(s.begin(),s.end());
	int n=s.size();
	for(int j=n-1;j>=0;j--){
		cout<<s[j];
	}

	return 0;
	
}
