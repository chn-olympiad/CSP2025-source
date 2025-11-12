#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string s;
int n,cd;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	cd=s.size();
	for(int i=0;i<cd;i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(i==1||s[i-1]!='-'){
				a[++n]=s[i]-'0';
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
