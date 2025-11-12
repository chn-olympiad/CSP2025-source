#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
char s[N];
priority_queue<int,vector<int> , less<int> > q;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		if((int)s[i] >= (int)'0' && (int)s[i] <= (int)'9'){
			q.push((int) s[i] - '0');
		}
	}
	while(q.size()){
		printf("%d",q.top());
		q.pop();
	}
	return 0;
}
