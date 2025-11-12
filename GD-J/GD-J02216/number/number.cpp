#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout); 
	string s;
	cin>>s; 
	int len=s.length(),num[1000010],cnt=0;
	for(int i=0;i<=len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[++cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	}
	return 0;
}
