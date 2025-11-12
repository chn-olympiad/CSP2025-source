#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+10;
int a[N]={0};
int askll(char c){
	return int(c)-48;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	if(len==1){
		if(s[0]>='0' && s[0]<='9'){
			cout<<s[0];
			return 0;
		}
	}
	int x=0;
	for(int i=0;i<len;i++){	
		char c=s[i];
		if(c<='9' && c>='0'){
			x++;
			a[x]+=askll(c);
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
