#include<bits/stdc++.h>
using namespace std;
string s;
int len,k[10];
bool f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			k[s[i]-'0']++;
			if(s[i]!='0')f=1;
		}
	}
	if(f==0)cout<<"0";
	else{
		for(int i=9;i>=0;--i){
			while(k[i]>0){
				cout<<i;
				k[i]--;
			}
		}
	}
    return 0;
}
