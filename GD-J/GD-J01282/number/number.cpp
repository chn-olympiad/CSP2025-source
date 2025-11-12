#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number1.in.txt","r",stdin);
	freopen("number1.out.txt","w",stdout);
	string s;
	getline(s);
	int a[1000000],cd=s.size();
	for(int i=0;i<=cd;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
		}
	}
	for(int i=0;i<cd;i++){
		for(int j=0;j<cd;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}
	}
	for(int i=0;i<cd;i++){
		cout<<a[i];
	}
	return 0;
} 
