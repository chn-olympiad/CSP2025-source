#include <bits/stdc++.h>
using namespace std;
#define M 100007
string s[20010][3];
int next[50010];
int ans=0;
vector<int> h[100010];

void check(string s1,string s2,string t1,string t2){
	next[0]=-1;
	int j=-1;
	for(int i=1;i<s1.size();i++){
		while(j!=-1&&s1[i]!=s1[j+1]) j=next[j];
		if(s1[i]==s1[j+1]) j++;
		next[i]=j;
	}
	j=-1;
	for(int i=0;i<t1.size();i++){
		while(j!=-1&&t1[i]!=s1[j+1]) j=next[j];
		if(t1[i]==s1[j+1]) j++;
		if(j==s1.size()-1){
			int flag=1;
			for(int k=i-s1.size()+1;k<=i;k++){
				if(t2[k]!=s2[k-(i-s1.size()+1)]) flag=0;
			}
			if(flag) ans++;
			else j=next[j];
		}
	}
}
int hash(string s1,string s2,int b){
	int f=0,res=0;
	//cout<<1<<endl;
	for(int i=0;i<s1.size();i++){
		if(!f){
			if(s1[i]!=s2[i]) f=1;
			else continue;
		}
		if(s1[i]==s2[i]) continue;
		res=(res*b+abs(s1[i]-s2[i]))%M;
		//cout<<res<<endl;	
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string t1,t2;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		h[hash(s[i][1],s[i][2],31)].push_back(i);
		//cout<<hash(s[i][1],s[i][2],31)<<' ';
	}	
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>t1>>t2;
		int hv=hash(t1,t2,31);
		//int hv =44;
		for(int j=0;j<h[hv].size();j++)
			check(s[h[hv][j]][1],s[h[hv][j]][2],t1,t2);
		printf("%d\n",ans);
	}
	return 0;
}

