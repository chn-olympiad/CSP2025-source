#include<bits/stdc++.h>
using namespace std;
char a[1000005];
priority_queue<char>q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	scanf("%s",a);
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(isdigit(a[i]))q.push(a[i]);
	}
	while(!q.empty()){
		printf("%c",q.top());
		q.pop();
	}
	return 0;
}