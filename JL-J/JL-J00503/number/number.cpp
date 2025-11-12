#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()<=1) cout<<s;
	else if(s.size()<=2){
		if(s[0]>='0'&&s[0]<='9') cout<<s[0];
		else if(s[1]>='0'&&s[1]<='9') cout<<s[1];
	}else{
		int ai=0;
		for(int i=0;i<s.size();i++){
			int t;
			if(s[i]>='0'&&s[i]<='9') {
				if(s[i]=='0') t=0;
				if(s[i]=='1') t=1;
				if(s[i]=='2') t=2;
				if(s[i]=='3') t=3;
				if(s[i]=='4') t=4;
				if(s[i]=='5') t=5;
				if(s[i]=='6') t=6;
				if(s[i]=='7') t=7;
				if(s[i]=='8') t=8;
				if(s[i]=='9') t=9;
				a[ai]=t;
				ai++;
			}
		}
		sort(a,a+ai);
		for(int i=ai-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
}
