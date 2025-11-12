#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string ans="",n;
int tmp2;
char tmp[N];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
		if('0'<=n[i]&&n[i]<='9')
			tmp[tmp2++]=n[i];
	sort(tmp,tmp+tmp2,cmp);
	for(int i=0;i<tmp2;i++)
		ans+=tmp[i];
	cout<<ans;
}
