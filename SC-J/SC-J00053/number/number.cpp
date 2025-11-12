#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N=1e6+5;
char s[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>(s+1);
	int len=strlen(s+1);
	priority_queue<int> q;
	for(int i=1;i<=len;i++){
		if(s[i]<'0' || s[i]>'9')
			continue;
//		cout<<s[i]<<'\n';
		q.push(s[i]-'0');
	}
	
	while(!q.empty()){
		cout<<q.top();
		q.pop();
	}
	return 0;
}