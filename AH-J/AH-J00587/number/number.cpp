#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt=1;
bool cmp(int x,int y){
	return x>y;
}
string s;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
for(int i=0;i<s.size();i++){
	if(s[i]>='0'&&s[i]<='9'){
		a[cnt]=s[i]-'0';
		cnt++;
	}
}
sort(a+1,a+cnt+1,cmp);
for(int i=1;i<=cnt-1;i++){
	cout<<a[i];
}
fclose(stdin);
fclose(stdout);
	return 0;
}
