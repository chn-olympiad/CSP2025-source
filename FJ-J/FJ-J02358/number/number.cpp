#include<bits/stdc++.h>
typedef long long ll;
const int maxn=1e6+10;
using namespace std;
string str;
int num[100];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	cin>>str;
	for (int i=0;i<str.size();++i)
	{
		if (str[i]>='0' && str[i]<='9')
			num[str[i]-'0']++;
	}
	
	int fl=0;
	for (int i=9;i>=1;--i)
		for (int j=1;j<=num[i];++j)
			printf("%d",i),fl=1;
	
	if (!fl) num[0]=min(num[0],1);
	for (int i=1;i<=num[0];++i)
		printf("%d",0);
} 
