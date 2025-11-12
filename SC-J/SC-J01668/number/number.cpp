#include<bits/stdc++.h>
using namespace std;
int a[1000005],top=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=(int)s.size();i++){
		if((int)s[i]>='0'&&(int)s[i]<='9'){
			a[top]=(int)s[i]-'0';
			top++;
		}
	}
	sort(a+1,a+top);
	if(a[top-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=top-1;i>0;i--){
		cout<<a[i];
	}
	return 0;
}