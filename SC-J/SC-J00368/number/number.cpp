#include<bits\stdc++.h>
using  namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[100005],num=0;
	string s;
	cin>>s;
	for(int i=0;i<=s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a+1,a+num+1,cmp);
	for(int i=1;i<=num;i++){
		cout<<a[i];
	}
	return 0;
}