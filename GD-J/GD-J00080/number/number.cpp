#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;;i++){
		if(s[i]<='9'&&s[i]>='0'){
			n++;
			a[n]=s[i]-'0';
		}else if(s[i]<='z'&&s[i]>='a'){
		}else{
			break;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
