#include <bits/stdc++.h>
using namespace std;
string s;
bool v[1000005];
void sc(){
	int ln=s.size(),k=0;
	bool flag=1;
	while(1){
		flag=1;
		for(int i=k+1;i<ln;i++){
			if(s[k]<s[i]){
				swap(s[k],s[i]);
				flag=0;
			}
		}
		k++;
		if(flag==1){
			for(int i=0;i<ln;i++){
				if(s[i]<='9' && s[i]>='0') cout<<s[i];
			}
			return;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ln=s.size();
	if(ln==1){
		cout<<s;
		return 0;
	}
	sc();
	return 0;
}
