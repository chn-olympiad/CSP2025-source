#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int b[N];
string ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int tot=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') b[++tot]=s[i]-'0';
	}
	sort(b+1,b+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		ans+=(char)(b[i]+'0');
	}
	cout<<ans;
	return 0;
} 