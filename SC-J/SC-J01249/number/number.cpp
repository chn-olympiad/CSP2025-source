#include<bits/stdc++.h>
using namespace std;
long long n[300000];
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1,ch=getchar();}
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')n[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(n[i]>0){
			for(int j=1;j<=n[i];j++)cout<<i;
		}
	}
	return 0;
} 