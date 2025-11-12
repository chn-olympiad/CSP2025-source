#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
priority_queue<char> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			q.push(s[i]);
		}
	}
	while(!q.empty()){
		printf("%c",q.top());
		q.pop();
	}
	return 0;
}
