#include<algorithm>
#include<iostream>
using namespace std;
int n;
string s,ans;
bool cmp(char a,char b){return a>b;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;n=s.size();
	for(int i=0;i<n;i++)if(s[i]>='0'&&s[i]<='9')ans+=s[i];
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}
