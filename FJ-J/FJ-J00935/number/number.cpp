#include<bits/stdc++.h>
using namespace std;
int a[100005],a1=0,num=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++a1]=s[i]-'0';
		}
	}
	sort(a+1,a+1+a1,greater<int>());
	for(int i=1;i<=a1;i++){
		num=num*10+a[i];
	}
	cout<<num;
	fclose(stdin);fclose(stdout);
	return 0;
}
