#include<bits/stdc++.h>
using namespace std;
char q[10001];
char q2[10001];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char e='0',y='-1',k;
	int u=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			u+=1;
	        q[u]=s[i]-48;
			q2[u]=s[i]-48;
		}
		}
	
	for(int j=1;j<=u-1;j++){
		for(int i=1;i<=u-1;i++){
			q[j]=max(q[j],q2[j+i]);
			q2[j]=max(q2[j],q[j+i]);
		}
		for(int i=1;i<=u-1;i++){
			if(q2[i]==q[j]){
				q2[i]=0;
			}
		}
	}
	for(int i=1;i<=u-1;i++){
		q[1]*=10;
	}
	if(u==1)cout<<e;
	return 0;
}

