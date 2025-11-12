#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int num[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size(),sum=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9')
			num[sum]=s[i]-'0',sum++;
	}
	sort(num,num+sum);
	for(int i=sum-1;i>=0;i--)
		cout<<num[i];
	return 0;
}