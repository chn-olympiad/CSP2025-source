#include<bits/stdc++.h>
using namespace std;
vector<int> vec1[200010],vec2[200010];
int len[200010],vis[200010];
string s[200010][3];
char t1[5000010],t2[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1];
		len[i]=s[i][1].length();
		s[i][1]=" "+s[i][1];
		int k=0;
		vec1[i].push_back(-1);
		vec1[i].push_back(0);
		for(int j=2;j<=len[i];j++){
			while(k && s[i][1][k+1]!=s[i][1][j])k=vec1[i][k];
			if(s[i][1][k+1]==s[i][1][j])k++;
			vec1[i].push_back(k);
		}
		cin>>s[i][2];
		s[i][2]=" "+s[i][2];
		k=0;
		vec2[i].push_back(-1);
		vec2[i].push_back(0);
		for(int j=2;j<=len[i];j++){
			while(k && s[i][2][k+1]!=s[i][2][j])k=vec2[i][k];
			if(s[i][2][k+1]==s[i][2][j])k++;
			vec2[i].push_back(k);
		}
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		if(strlen(t1+1)!=strlen(t2+1)){
			puts("0");
			continue; 
		}
		int m=strlen(t1+1),ans=0;
		int pre=1;
		while(t1[pre]==t2[pre])pre++;
		int suf=m;
		while(t1[suf]==t2[suf])suf--;
		for(int i=1;i<=n;i++){
			if(suf-pre+1>len[i])continue;
			int L=suf-len[i]+1,R=pre+len[i]-1;
			if(R-L+1<len[i])continue;
			vector<int> v1,v2;
			v1.clear();
			v2.clear();
			int k=0;
			for(int j=L;j<=R;j++){
				while(k && s[i][1][k+1]!=t1[j])k=vec1[i][k];
				if(s[i][1][k+1]==t1[j])k++;
				if(k==len[i])v1.push_back(j-len[i]+1);
			}
			k=0;
			for(int j=L;j<=R;j++){
				while(k && s[i][2][k+1]!=t2[j])k=vec2[i][k];
				if(s[i][2][k+1]==t2[j])k++;
				if(k==len[i])v2.push_back(j-len[i]+1);
			}
			for(int j:v1)vis[j]=1;
			int flag=0;
			for(int j:v2)flag|=vis[j];
			for(int j:v1)vis[j]=0;
			ans+=flag;
		} 
		printf("%d\n",ans);
	}
	return 0;
}
//50,18:05
