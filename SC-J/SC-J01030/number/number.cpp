#include<bits/stdc++.h>
using namespace std;
int a[1000009];
string s;



int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	int o=0;
	int l=s.size();
	for(int j=0;j<l;j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[o]=s[j]-48;
			o++;
		}
	}
//	for(int j=0;j<o;j++){
//		cout<<a[j];
//	}
//	cout<<"\n";
	sort(a,a+o);
	for(int j=o-1;j>=0;j--){
		cout<<a[j];
	}
	cout<<"\n";
	return 0;
} 