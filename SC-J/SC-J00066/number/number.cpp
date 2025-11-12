#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
char ch[N];
priority_queue<ll> q;
ll len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>(ch+1);
	len=strlen(ch+1);
	for(int i=1;i<=len;i++)
		if(ch[i]>='0' && ch[i]<='9')
			q.push(ch[i]-'0');
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}