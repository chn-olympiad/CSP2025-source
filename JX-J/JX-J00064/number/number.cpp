#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
int a[N],b[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			b[s[i]-'0']++;
	if(!b[1]&&!b[2]&&!b[3]&&!b[4]&&!b[5]&&!b[6]&&!b[7]&&!b[8]&&!b[9]){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--)
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	return 0;
}
