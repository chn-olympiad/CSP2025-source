#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[15];
string ans;

int read(){
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	int len=s.size();
	for (int i=0;i<len;i++){
		if (s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		if (!cnt[i])
			continue;
		while(cnt[i]){
			if (i==9)
				ans+='9';
			else if (i==8)
				ans+='8';
			else if (i==7)
				ans+='7';
			else if (i==6)
				ans+='6';
			else if (i==5)
				ans+='5';
			else if (i==4)
				ans+='4';
			else if (i==3)
				ans+='3';
			else if (i==2)
				ans+='2';
			else if (i==1)
				ans+='1';
			else if (i==0)
				ans+='0';
			cnt[i]--;
		}
	}
	cout <<ans<<endl;
	return 0;
}