#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	string a;
	int n;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a=a+s[i];
		}
	}
	for(int j=0;j<a.size();j++){
		for(int i=0;i<a.size()-1;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}cout<<a;
	return 0;
}
