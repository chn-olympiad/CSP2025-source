#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
bool flag;
int  main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=(int)s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			flag=1;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			a[i]--;
			cout<<i;
		}
	}
}