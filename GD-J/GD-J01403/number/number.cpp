#include<bits/stdc++.h>
using namespace std;
int num[1000005];
string s;
int j=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[j]=s[i]-'0';
			j++;
		}
	}
	sort(num+1,num+j+1,cmp);
	for(int i=1;i<j;i++){
		cout<<num[i];
	}
	return 0;
}
