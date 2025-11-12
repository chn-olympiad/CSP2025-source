#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2;
int n,q;
int f1[200005],f2[200005],ton1[5000006],ton2[5000006];
int find(string s){
	for(int i=0;i<s.size();i++){
		if(s[i]=='b') return i;
	}
	return -1;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
} 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		f1[i]=find(s1[i]);
		f2[i]=find(s2[i]);
		cout<<f1[i]<<' '<<f2[i]<<'\n';
		if(f1[i]<0||f2[i]<0) continue;
		if(f1[i]-f2[i]>=0) ton1[f1[i]-f2[i]]++;
		else ton2[f2[i]-f1[i]]++;
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		x=find(t1);
		y=find(t2);
		if(t1.size()!=t2.size()||x<0||y<0){
			cout<<0<<'\n';
			continue;
		}
		if(x>=y) cout<<ton1[x-y]<<'\n';
		else cout<<ton2[y-x]<<'\n';
	}
	return 0;
}

