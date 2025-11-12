#include<cstdio>
#include<bits/stdc++.h> 
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,m;
	cin>>s;
	int suu=0;
	if(s.size()==1){
		cout<<s;
		return 0;
	} 
	for(int i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			m[suu]=s[i];
			suu++;
		}
	}
	for(int i=0;i<=suu+1;i++){
		if(m[i]<m[i+1]){
			int g=i+1;
			while(m[i]<m[g]){
				char zrl=m[i];
			m[i]=m[g];
			m[g]=zrl;
			g++;
			}
		}	
	}
	for(int i=0;i<=suu+1;i++){
		cout<<m[i];
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
