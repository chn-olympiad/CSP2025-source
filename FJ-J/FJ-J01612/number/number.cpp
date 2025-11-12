#include<bits/stdc++.h>
using namespace std;
int a[1000005],x=0;
int main(){
	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}