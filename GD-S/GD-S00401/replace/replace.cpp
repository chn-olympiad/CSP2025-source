#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,end1[5000010],end2[5000010],size[5000010],size2[5000010];
string s1,s2,t1,t2;
struct stu{
	int a[26];
}a[5000010][2];
int fail[5000010],fail2[5000010];
int cnt,cnt2,ans;
void add(string s,string s2,int k){
	int now=0,now2=0;
	for(int i=0;i<s.size();i++){
		int x=s[i]-'a',x2=s2[i]-'a';
		if(!a[now][0].a[x])a[now][0].a[x]=++cnt;
		now=a[now][0].a[x];
		if(!a[now2][1].a[x2])a[now2][0].a[x2]=++cnt2;
		now2=a[now2][1].a[x2];
	}
	end1[now]=k;
	end2[now2]=k;
}
void f(){
	queue<int>q,q2;
	for(int i=0;i<26;i++){
		if(a[0][0].a[i])q.push(a[0][0].a[i]),size[a[0][0].a[i]]=1;
	}
	for(int i=0;i<26;i++){
		if(a[0][1].a[i])q2.push(a[0][1].a[i]),size2[a[0][1].a[i]]=1;
	}
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			if(a[t][0].a[i])size[a[t][`0].a[i]]=size[t]+1,q.push(a[t][0].a[i]),fail[a[t][0].a[i]]=a[fail[t]][0].a[i];
			else a[t][0].a[i]=a[fail[t]][0].a[i];
		}
		cout<<'\n';
	}
	while(!q2.empty()){
		int t=q2.front();
		q2.pop();
		for(int i=0;i<26;i++){
			if(a[t][1].a[i])size2[a[t][1].a[i]]=size2[t]+1,q.push(a[t][1].a[i]),fail2[a[t][1].a[i]]=t;
			else a[t][1].a[i]=a[fail2[t]][1].a[i];
		}
	}
}
void find(string t1,string t2){
	int now,now2;
	now=0,now2=0;
	for(int i=0;i<t1.size();i++){
		int x=t1[i]-'a',x2=t2[i]-'a';
		now=a[now][0].a[x],now2=a[now2][1].a[x2];
		if(i>=r){
			bool c[5000010]={0};
			for(int j=now;j&&i-size[j]<=l;j=fail[j]){
				if(end1[j])c[end1[j]]=1;
			}
			for(int j=now2;j&&i-size2[j]<=l;j=fail2[j])
				if(end2[j]&&c[end2[j]])ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		add(s1,s2,i);
	}
	f();
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){puts(0);continue;}
		l=r=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]&&!l)l=j;
			if(t1[j]!=t2[j])r=j;
		}
		find(t1,t2);
		cout<<ans<<"\n";
	}
	return 0;
}

