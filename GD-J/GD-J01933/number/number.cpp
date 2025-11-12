#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int num[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt = 0;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			cnt++;
			num[cnt]=s[i]-'0';
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=0;i<cnt;i++)cout<<num[cnt-i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
