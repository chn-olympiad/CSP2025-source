#include<bits/stdc++.h>
using namespace std;
char ch[100005];
int sch;
bool pd(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9')ch[++sch]=s[i];
	}
	sort(ch+1,ch+sch+1,pd);
	for(int i=1;i<=sch;i++){
		cout<<ch[i];
	}
} 
