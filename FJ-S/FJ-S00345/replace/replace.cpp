#include<bits/stdc++.h>
using namespace std;
int n;
string p1,p2;
string f1[200005],f2[200005];
vector<int>q1[100005],q2[100005];
int kmp(int x){
	p1=' '+p1;
	int lst=0;
	q1[x].push_back(-1);
	q1[x].push_back(0);
	for(int i=2;i<p1.size();i++){
	  while(lst!=-1&&p1[i]!=p1[lst+1]){
	  lst=q1[x][lst];
	  }
	  lst++;
	  q1[x].push_back(lst);
	}
	return 0;
}
int kmp2(int x){
	p2=' '+p2;
	int lst=0;
	q2[x].push_back(-1);
	q2[x].push_back(0);
	for(int i=2;i<p2.size();i++){
	  while(lst!=-1&&p2[i]!=p2[lst+1]){
	  lst=q2[x][lst];
	  }
	  lst++;
	  q2[x].push_back(lst);
	}
	return 0;
}
string s1,s2;
int tag(int x,int fl,int sr){
	priority_queue<int>q;
	int sl=sr-f1[x].size()+2;
	int tmp=0;
	for(int i=sl;i<=min(s1.size()-1,fl+f1[x].size()-2);i++){
		while(s1[i]!=f1[x][tmp+1]&&tmp!=-1)
			tmp=q1[x][tmp];
		tmp++;
		if(tmp==f1[x].size()-1)q.push(i),tmp=q1[x][tmp];
	}
	sl=sr-f2[x].size()+2;
	tmp=0;
	for(int i=sl;i<=min(s2.size()-1,fl+f2[x].size()-2);i++){
		while(s2[i]!=f2[x][tmp+1]&&tmp!=-1)
			tmp=q2[x][tmp];
		tmp++;
		if(tmp==f2[x].size()-1)q.push(i),tmp=q2[x][tmp];
	}
	int ans=0;
	int opt=-1;
	while(q.size()){
		if(opt==q.top())ans++;
		opt=q.top();
		q.pop();
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	if(n*q>=1e7){
		while(q--)
		 cout<<0<<endl;
		 return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>p1>>p2;
		f1[i]=' '+p1,f2[i]=' '+p2;		
		kmp(i),kmp2(i);
	}
	while(q--){
		cin>>s1>>s2;
		s1=' '+s1,s2=' '+s2;
		int l,r;
		for(int i=0;i<s1.size();i++)
		 if(s1[i]!=s2[i]){
		 	l=i;
		 	break;
		 }
		for(int i=s1.size()-1;i>=0;i--)
			if(s1[i]!=s2[i]){
		 	r=i;
		 	break;
		 }
		long long ans=0;
		for(int i=1;i<=n;i++)
		ans+=tag(i,l,r);
		printf("%lld\n"ans);
	}
}
