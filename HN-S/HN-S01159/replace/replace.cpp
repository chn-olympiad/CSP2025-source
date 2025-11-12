#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int nxt1[3000010];
int nxt2[3000010];
int f1[3000010],f2[3000010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],s1[i]=" "+s1[i],s2[i]=" "+s2[i];
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int m=t1.size();
		t1=" "+t1;
		t2=" "+t2;
		int l=1,r=m;
		while(t1[l]==t2[l])l++;
		while(t1[r]==t2[r])r--;
		nxt1[1]=0;
		nxt2[1]=0;
		string r1=" "+t1.substr(l,r-l+1);
		string r2=" "+t2.substr(l,r-l+1);
		int sz=r-l+1;
		for(int i=2,j=0;i<=sz;i++){
			while(j>0&&r1[i]!=r1[j+1])j=nxt1[j];
			if(r1[i]==r1[j+1])j++;
			nxt1[i]=j;
		}
		for(int i=2,j=0;i<=sz;i++){
			while(j>0&&r2[i]!=r2[j+1])j=nxt2[j];
			if(r2[i]==r2[j+1])j++;
			nxt2[i]=j;
		}
		for(int p=1;p<=n;p++){
			for(int i=1,j=0;i<=s1[p].size()-1;i++){
				while(j>0&&(j==sz||r1[j+1]!=s1[p][i]))j=nxt1[j];
				if(r1[j+1]==s1[p][i])j++;
				f1[i]=j;
				//cout<<f1[i]<<' ';
			}
			//cout<<endl;
			for(int i=1,j=0;i<=s2[p].size()-1;i++){
				while(j>0&&(j==sz||r2[j+1]!=s2[p][i]))j=nxt2[j];
				if(r2[j+1]==s2[p][i])j++;
				f2[i]=j;
				//cout<<f2[i]<<' ';
			}
			//cout<<endl;
			for(int i=1;i<=s1[p].size()-1;i++)
				if(f1[i]==f2[i]&&f1[i]==sz){
					bool flag=1;
					for(int j=i+1;j<=s1[p].size()-1;j++)
						if(r+j-i>m||s2[p][j]!=t2[r+j-i])flag=0;
					for(int j=i-sz;j>=1;j--)
						if(r+j-i<=0||s2[p][j]!=t2[r+j-i])flag=0;
					if(flag)ans++;
					break;
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}
