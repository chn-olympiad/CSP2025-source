#include<bits/stdc++.h>
using namespace std; 
string s;
int dight[11];
bool f=true;

int main(){
	memset(dight,0,sizeof(dight));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			dight[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(i==0&&f){
			cout<<0;
			return 0;
		}
		if(i!=0&&dight[i]!=0)f=false;
		for(int j=1;j<=dight[i];j++)cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
