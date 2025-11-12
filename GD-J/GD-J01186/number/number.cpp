#include<bits/stdc++.h>
using namespace std;
int len,len_num;
const int N=1e6+10;
char s[N];
vector<char>num;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i=0;s[i]!='\0';i++) if(s[i]>='0'&&s[i]<='9') num.push_back(s[i]),len_num++; 
	sort(num.begin(),num.end(),cmp);
	for(int i=0;i<len_num;i++) cout<<num[i];
	return 0;
} 
