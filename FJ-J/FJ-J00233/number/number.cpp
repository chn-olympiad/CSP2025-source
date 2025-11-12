#include <iostream>
using namespace std;

string s;
int cnt[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=0;i<s.length();++i){
		if (s[i]>='0' and s[i]<='9')
			cnt[s[i]-'0']++;
	} for (int i=9;i>=0;--i){
		for (int j=1;j<=cnt[i];++j)
			cout << i;
	} return 0;
}

/*
#include <iostream>
using namespace std;

string s;
int cnt[15];

int man(){
	for (int i=0;i<s.length();++i){
		if (s[i]>='0' and s[i]<='9')
			cnt[s[i]-'0']++;
	} for (int i=9;i>=0;--i){
		for (int j=1;j<=cnt[i];++j)
			cout << i;
	} return 0;
}

int mian(){
	cin >> s;
	man();
	return 0;
}

int main(){
	//freeopen
	//froepen
	//freopon
	//feropen
	//freepen
	//frepen
	//fropen
	//"number.ans"
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=mian();
	return 0;
}
RP++*/
