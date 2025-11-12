#include<bits/stdc++.h>
using namespace std;
int a[1000005],index=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[index]=s[i]-'0';
			index++;
		}
	}
	sort(a+1,a+index);
	for(int i=index-1;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
