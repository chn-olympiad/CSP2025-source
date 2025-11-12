#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string s1;
	if(s.size()==1&&s[0]>='0'&&s[0]<='9'){
		cout<<s;
	}else{
		for(int i=0;i<s.size();i++){
			if(s[i]>='0'&&s[i]<='9'){
				s1+=s[i];
			}
		}
		for(int i=0;i<s1.size();i++){
			for(int j=0;j<s1.size()-1-i;j++){
				if(s1[j]-'0'<=s1[j+1]-'0'){
					swap(s1[j],s1[j+1]);
				}
			}
		}
		cout<<s1;
	}
	return 0;
}


