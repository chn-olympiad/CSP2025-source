#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	for(int i=1;i<=s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++a[0]]=s[i]-'0';
		}
	}
	sort(a+1,a+1+a[0],cmp);
	for(int i=1;i<=a[0];i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
