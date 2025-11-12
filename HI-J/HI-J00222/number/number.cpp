#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s1="";
	cin>>s;
	int g=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1[g]=s[i];
			g++;
		}
	}
	for(int i=0;i<=g;i++){
		for(int j=1;j<g;j++){
			if(s1[j-1]<s1[j]){
				char temp=s1[j];
				s1[j]=s1[j-1];
				s1[j-1]=temp;
			}
		}
	}
	for(int i=0;i<=g;i++){
		cout<<s1[i];
	}
	return 0;
}

