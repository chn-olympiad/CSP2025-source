#include<bits/stdc++.h>
using namespace std;
int v=0;
string s;
int ans[1000010];
bool vis[1000010];
bool bf(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans[v]=int(s[i])-48;
			v++;
		}
		
	}
	sort(ans+0,ans+v,bf);
	for(int i=0;i<v;i++){
		cout<<ans[i];
	}
	return 0;
}
