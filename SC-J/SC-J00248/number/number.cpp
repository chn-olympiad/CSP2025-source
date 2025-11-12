#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<=len;i++) a[i]=-1e9;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9') a[i]=s[i]-'0';
	}
	sort(a,a+len,cmp);
	if(a[0]==0){
		cout<<0;
	}
	else{
		for(int i=0;i<len;i++){
			if(a[i]!=-1e9) cout<<a[i];
			else return 0;
		}
	}
	return 0;
} 