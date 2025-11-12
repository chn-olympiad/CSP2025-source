#include<bits/stdc++.h>
using namespace std;
int maxn[1000005],maxi=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			maxn[maxi]=s[i]-'0';
			maxi++;
		}
	}
	sort(maxn+1,maxn+1+maxi,cmp);
	for(int i=1;i<maxi;i++)printf("%d",maxn[i]);
	return 0;
}