#include<iostream>
#include<algorithm>
using namespace std;
long long num[2000000],cnt=0,tot;
char s[2000000];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s[++tot]){
		
	}
	for(int i=1;i<=tot;i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[++cnt]=s[i]-'0';
//			cout<<num[cnt];
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)cout<<num[i];
	return 0;
}

