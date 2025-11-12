#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len,kk;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len2=s.size();
	for(int i=0;i<len2;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[len]=(s[i]-'0');
			len++;
		}
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--){
		if(a[i]==0&&kk==0){
		}else{
			cout<<a[i];
			kk=1;
	    }
	}
	if(kk==0){
		cout<<0;
	}
	return 0;
}
