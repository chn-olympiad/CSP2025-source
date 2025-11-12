#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
char a[1000005];
ll cnt=0,RP=0;
bool cmp(const char &x,const char &y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(ll i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	bool flag=0;
	if(a[0]!='0'){
		flag=1;
	}
	for(ll i=0;i<cnt;i++){
		if(a[i]=='0'){
			RP++;
		}
		if(a[i]=='0'&&flag==1){
			printf("%c",a[i]);
		}
		else if(a[i]!='0'){
			printf("%c",a[i]);
		}
	}
	if(RP==cnt){
		cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
