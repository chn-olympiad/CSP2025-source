//#Shang4Shan3Ruo6Shui4
#include<bits/stdc++.h>
using namespace std;
string s;
int pd[20];
int tl;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	tl=s.size();
	for(int i=0;i<tl;i++){
		if('0'<=s[i]&&s[i]<='9')pd[s[i]-48]++;
	}
	for(int i=9;i>=0;i--)for(int o=1;o<=pd[i];o++)printf("%d",i);
	return 0;
}
