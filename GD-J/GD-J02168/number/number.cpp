#include<bits/stdc++.h>
using namespace std;
string s;
char a;
int n[100010];
int vis[100010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int len=0;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		int vv;
		vv=s[i];
		if(vv==48 or vv==49 or vv==50 or vv==51 or vv==52 or vv==53 or vv==54 or vv==55 or vv==56 or vv==57){
			n[i]=(vv-48);
		}
		else{
			n[i]=-1;
		} 
	}
	sort(n,n+len);
	for(int i=len;i>=0;i--){
		if(i==len){
			continue;
		}
		if(n[i]>=0){
			cout<<n[i];
		}
	}
	return 0;
} 
