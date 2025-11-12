#include<bits/stdc++.h>
using namespace std;
int number[100010],k,tmp=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int len=0;
	cin>>s;
	len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i-1]>='0'&&s[i-1]<='9'){
			number[tmp]=s[i-1]-'0';
			k++;
			tmp++;
		}
			
	}
	sort(number,number+len,cmp);
	for(int i=0;i<=k-1;i++)
		cout<<number[i];
	return 0;
}