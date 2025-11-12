#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),t=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}for(int i=9;i>=0;i--){
		if(a[i]==0){
			continue;
		}else{
			for(int j=0;j<a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
} 
