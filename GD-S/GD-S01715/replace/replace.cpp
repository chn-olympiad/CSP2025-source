#include<bits/stdc++.h>
#define ll long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=2e4+44,K=12;
int n,q;
vector<int>a[N],f[N];
string s1,s2;

vector<int> turn(string s1,string s2){
	int len=s1.size();
	vector<int>a(s1.size()+1);
	for(int i=1;i<=len;i++)a[i]=(s1[i-1]-'a')*26+(s2[i-1]-'a');
	return a;
}
vector<int>kmp(vector<int>a){
	int len=a.size();
	vector<int>f(len);
	for(int i=2,j=0;i<len;i++){
		while(j&&a[j+1]!=a[i])j=f[j];
		if(a[j+1]==a[i])j++;
		f[i]=j;
	}
	return f;
}
int check(vector<int>p,int x,int l,int r){
	int lenp=p.size(),lena=a[x].size(),cnt=0;
	if(r-l+1>lena)return 0;
	for(int i=1,j=0;i<lenp;i++){
		while(j&&a[x][j+1]!=p[i])j=f[x][j];
		if(a[x][j+1]==p[i])j++;
		if(j+1==lena){
			j=f[x][j];
			if(i>=r&&i-lena+1<=l)cnt++;
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1>>s2,f[i]=kmp(a[i]=turn(s1,s2));
	while(q--){
		cin>>s1>>s2;
		int cnt=0,l=0,r=s1.size()-1;
		vector<int>p=turn(s1,s2);
		while(l<s1.size()&&s1[l]==s2[l])l++;
		while(r>=0&&s1[r]==s2[r])r--;
	//	cout<<l<<' '<<r<<'\n';
		for(int i=1;i<=n;i++)cnt+=check(p,i,l,r);
		cout<<cnt<<'\n';
	}
}
	
