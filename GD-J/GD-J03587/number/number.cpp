#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a="";
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a+=s[i];
		}
	}

	for(int i=0;i<a.size();i++){
		for(int j=i+1;j<a.size();j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
		cout<<a;
		fclose(stdin);
		fclose(stdout);
	return 0;
}
