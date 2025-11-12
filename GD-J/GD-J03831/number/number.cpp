#include<bits/stdc++.h>
using namespace std;
string s;
int op[10],rik;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			rik=s[i]-'0';
			op[rik]++;
		}
	}
	for(int i=1;i<=op[9];i++)printf("%d",9);
	for(int i=1;i<=op[8];i++)printf("%d",8);
	for(int i=1;i<=op[7];i++)printf("%d",7);
	for(int i=1;i<=op[6];i++)printf("%d",6);
	for(int i=1;i<=op[5];i++)printf("%d",5);
	for(int i=1;i<=op[4];i++)printf("%d",4);
	for(int i=1;i<=op[3];i++)printf("%d",3);
	for(int i=1;i<=op[2];i++)printf("%d",2);
	for(int i=1;i<=op[1];i++)printf("%d",1);
	for(int i=1;i<=op[0];i++)printf("%d",0);
	return 0;
}
