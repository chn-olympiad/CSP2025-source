#include<bits/stdc++.h>
using namespace std;
string s,t;
bool flag;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
            if(s[i]!='0') flag=1;
			t=t+s[i];
		}
	}
	sort(t.begin(),t.end(),cmp);
	if(flag==0) cout<<0;
	else cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
