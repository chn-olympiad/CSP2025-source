#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			s[i]=s[i];
		}else{
			s[i]='p';
		}
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
            if(s[j]=='p'){
                swap(s[j],s[s.size()]);
            }
            if(s[j]<=s[j+1]){
                swap(s[j],s[j+1]);
            }

        }
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='p'){
			continue;
		}
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
