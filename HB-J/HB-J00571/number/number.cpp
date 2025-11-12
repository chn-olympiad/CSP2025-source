#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000010];
int cnt=0;

bool cmp(char a1,char a2){
	if(a1=='0') return false;
	if(a2=='0') return true;
	return a1>a2;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[cnt]=s[i];
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}
