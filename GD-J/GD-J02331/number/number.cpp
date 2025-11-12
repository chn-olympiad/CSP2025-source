#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cmt=0;
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cmt]=s[i]-'0';
			cmt++;
		}
	}
	sort(a,a+cmt+1);
	for(int i=cmt;i>0;i--){
		cout<<a[i];
	}
	
	return 0;
} 
