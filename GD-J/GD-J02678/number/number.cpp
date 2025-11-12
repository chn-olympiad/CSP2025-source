#include<bits/stdc++.h>
using namespace std;
string s;int num[1000020],c=1;

bool cmp(int x,int y){return x>y;}


int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[c]=s[i]-'0';
			c++;
		}
	}
	c--;
	sort(num+1,num+c+1,cmp);
	for(int i=1;i<=c;i++){
		cout<<num[i];
	}
	return 0;
}

