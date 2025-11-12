#include<bits/stdc++.h>
using namespace std;
string s,a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//		cin>>b;
//		s+=b;
//	}
	getline(cin,s);
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}
	for(int i=0;i<=a.size();i++){
		for(int j=i+1;j<=a.size();j++){
			if(a[j]>a[i]){
				swap(a[j],a[i]);
			}
		}
	}
	cout<<a;
	return 0;
} 
