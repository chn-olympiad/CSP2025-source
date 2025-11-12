#include<bits/stdc++.h>
using namespace std;
long long cnt[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
		   j++;
		   cnt[j]=s[i]-'0';
	    }
	}
	sort(cnt+1,cnt+j+1);
	for(int i=j;i>=2;i--){
		cout<<cnt[i];
	}
	return 0;
}
