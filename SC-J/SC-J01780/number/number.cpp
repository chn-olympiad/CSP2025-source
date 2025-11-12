#include<bits/stdc++.h>
using namespace std;

int in(){
	int t=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=k*10+c-'0';
		c=getchar();
	}
	return t*k;
}

void out(int x){
	if(x<0)x=-x,putchar('-');
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10);putchar(x%10+'0');
}

priority_queue<int> q;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			q.push(s[i]-'0');
		}
	}
	int ans=0;
	while(!q.empty()){
		int t=q.top();
		q.pop();
		out(t);
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 