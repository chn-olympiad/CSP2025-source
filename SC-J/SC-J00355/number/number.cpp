#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+9;
int num[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			num[++cnt]=s[i]-'0';
	sort(num+1,num+cnt+1,cmp);
	if(num[1]==0)printf("0");
	else{
		for(int i=1;i<=cnt;i++)
			printf("%d",num[i]);
	}
}