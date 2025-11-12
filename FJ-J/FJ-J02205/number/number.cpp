#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005];
priority_queue<int> q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int len,cnt=0;
	cin>>a;
	len=strlen(a);
	for(int i=0;i<len;i++){
		if('0'<=a[i]&&a[i]<='9') b[++cnt]=a[i]-'0';
	}
	for(int i=1;i<=cnt;i++){
		q.push(b[i]);
	}
	while(!q.empty()){
		int u=q.top();
		q.pop();
		cout<<u;
	}
	return 0;
}
