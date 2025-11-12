#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],L=0,ans=0;
string s[500007],pdk;
string change(int x){
	int pd1=0,pd2=1;
	string y;
	while(x>0){
		if((x-pd2)%(pd2*2)==0) y[pd1]='1';
		else y[pd1]='0';
		pd1++,pd2*=2;
	}
	return y;
}
void build(int x){
	int pd1=0,pd2=1;
	string y;
	while(x>0){
		if((x-pd2)%(pd2*2)==0) y[pd1]='1';
		else y[pd1]='0';
		pd1++,pd2*=2;
	}
	for(int i=0;i<=max(s[x-1].length(),y.length())-1;i++){
		if(i>s[x-1].length()-1) s[x][i]=y[i];
		else if(i>y.length()-1) s[x][i]=s[x-1][i];
		else s[x][i]=char(((s[x-1][i]-'0')+(y[i]-'0'))%2+48);
	}
}
bool pd(int l,int r){
	if(max(s[l].length(),s[r].length())!=pdk.length()) return 0; 
	for(int i=0;i<=pdk.length()-1;i++){
		if(i>s[l].length()) if(s[r][i]!=pdk[i]) return 0;
		if(i>s[r].length()) if(s[l][i]!=pdk[i]) return 0;
		if(s[l][i]==s[r][i]&&pdk[i]=='1') return 0;
		if(s[l][i]!=s[r][i]&&pdk[i]=='0') return 0;
	}
	return 1;
}
bool pdnk(){
	if(n>2||k!=0) return 0;
	if(n==1) cout<<0;
	else if(n==2) cout<<1;
	return 1;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	pdk=change(k);
	for(int i=1;i<=n;i++) cin>>a[i];
	if(pdnk()) return 0;
	for(int i=1;i<=n;i++) build(i);
	for(int li=1;li<=n;li++){
		if(li<=L) continue;
		for(int ri=li;ri<=n;ri++){
			if(pd(li,ri)) L=ri,ri=n,ans++;
		}
	}
	cout<<ans;
	return 0;
}
