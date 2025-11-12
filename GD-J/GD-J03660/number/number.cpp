#include<bits/stdc++.h>
using namespace std;
string s;
bool a[10000000];
char b[10000000];
int num;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<s;
		return 0;
	}	
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[j]=s[i];
			j++;
		}
	}
	sort(b,b+j,cmp);
	for(int x=0;x<j;x++){
		cout<<b[x];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
