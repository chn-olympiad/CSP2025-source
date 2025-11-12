#include<bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]>='0'&&s[i]<='9')
			ss+=s[i];
	//cout<<ss;
	long long len=ss.length();
	for(int i=len/2+1;i>0;i--){
		for(int j=0;i+j<len;j++){
			//cout<<ss[j]<<" "<<ss[i+j];
			if(ss[j]<ss[i+j]){
				swap(ss[j],ss[i+j]);
			}
			//cout<<" "<<ss<<endl;
		}
	}
	cout<<ss;
	return 0;
}
