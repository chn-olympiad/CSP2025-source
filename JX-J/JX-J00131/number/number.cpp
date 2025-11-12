#include<bits/stdc++.h>
using namespace std;
bool x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			x=1;
			cout<<s[i];
		}else if(x==1) return 0;
	}
	return 0;
}
