#include<bits/stdc++.h>
using namespace std;
char n[1000005];
int main(){
	freopen("number.in","r",stdin);
	 freopen("number.out","w",stdout);
	string s;
	int a=0;
		cin >>s;
		if(s.size()==1){
			cout <<s;
			return 0;
		}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[a]=s[i];
			a++;
		}
	}
	sort(n,n+a);
	for(int i=a-1;i>=0;i--){
		cout << n[i];
		continue;
	}
	return 0;
}

