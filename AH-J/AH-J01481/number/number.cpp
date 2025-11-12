#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string s;
int num[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>s;
	int len=s.size(),n=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
            num[++n]=s[i]-'0';
		}
	}
	sort(num+1,num+1+n);
	for(int i=n;i>=1;i--) cout<<num[i];
	return 0;
}

