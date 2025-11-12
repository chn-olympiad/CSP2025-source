#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000006];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')num[++cnt]=0;
		else if(s[i]=='1')num[++cnt]=1;
		else if(s[i]=='2')num[++cnt]=2;
		else if(s[i]=='3')num[++cnt]=3;
		else if(s[i]=='4')num[++cnt]=4;
		else if(s[i]=='5')num[++cnt]=5;
		else if(s[i]=='6')num[++cnt]=6;
		else if(s[i]=='7')num[++cnt]=7;
		else if(s[i]=='8')num[++cnt]=8;
		else if(s[i]=='9')num[++cnt]=9;
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--){
		cout<<num[i];
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}