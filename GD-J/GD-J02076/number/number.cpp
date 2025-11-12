#include <bits/stdc++.h>
using namespace std;
string s;
int l,f=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int num=9;num>=0;num--){
		for(int i=0;i<l;i++){
			if(s[i]=='0'+num){
				if(f==0&&s[i]=='0'){
					cout<<0;
					return 0;
				}
				f=1;
				cout<<num;
			}
		}
	}
	return 0;
}
