#include <bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int c=0;
	for(int i=0;i<s.size();i++){
		for(int j=48;j<=58;j++){
			if(s[i]-48==j-48){
				c++;
				b[c]=j-48;
				continue;
			}
		}
	}
	sort(b+1,b+c+1);
	for(int i=c;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
