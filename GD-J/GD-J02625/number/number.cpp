#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];//s中的数字 
int tmp=0;//数字的个数 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') a[tmp++]=s[i]-'0';
	}
	sort(a,a+tmp,cmp);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<tmp;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
