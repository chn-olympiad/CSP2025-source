#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s=" ";
int siz=0;
bool vis[maxn];
int n[maxn];
int maxx=0;
bool cmp(int x,int y){
	return x>y;
}
void ffind(){
	int le=s.size();
	for(int i=0;i<=le;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[++siz]=s[i]-'0';
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ffind();
	sort(n+1,n+siz+1,cmp);
	for(int i=1;i<=siz;i++){
		cout<<n[i];
	}
	
	return 0;
}
