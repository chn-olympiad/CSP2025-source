#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1e6+10;
int next[maxn],n;

bool cmp(int a,int b){
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			next[n++]=s[i]-'0';
			
	sort(next,next+n,cmp);
	
	for(int i=0;i<n;i++)
		cout<<next[i];
	cout<<endl;
	
	return 0;
}
