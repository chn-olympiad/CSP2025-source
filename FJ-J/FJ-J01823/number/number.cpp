#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[j]=b[j]+(s[i]-'0');
			j++;
		}
	}
	sort(b+1,b+1+j);
	for(int i=j;i>1;i--){
		cout<<b[i];
	}
	return 0;
}
