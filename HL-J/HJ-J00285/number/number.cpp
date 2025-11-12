#include<bits/stdc++.h>
using namespace std;
#define r return 0
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	if(a==1){
		if(s[0]>='0' and s[0]<='9'){
			cout<<s;
			r;
		}
		if(s[0]<'0' or s[0]>'9'){
			r;
		}
	}
	if(a==2){
		if(s[0]>='0' and s[0]<='9'){
			if(s[0]<s[1]){
				cout<<s[1]<<s[0];
				r;
			}
			else{
				cout<<s[0]<<s[1];
				r;
			}
		}
		else{
			if(s[0]<'0' or s[0]>'9'){
				if(s[1]>'0' and s[1]<'9'){
					cout<<s[1];
					r;
				}
				else{
					r;
				}
			}
			else{
				if(s[1]>'0' and s[1]<'9'){
					if(s[0]<s[1]){
						cout<<s[1]<<s[0];
						r;
					}
					else{
						cout<<s[0]<<s[1];
						r;
					}
				}
				else{
					cout<<s[0];
					r;
				}
			}
		}
	}
	return 0;
}