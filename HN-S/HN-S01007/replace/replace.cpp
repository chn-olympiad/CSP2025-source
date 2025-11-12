#include<bits/stdc++.h>
using namespace std;
//substr(id,n):从id开始截取n个
//s.find(string) 如果string在s里的话，返回其的下标，否则-1 
#define key first
#define val second
string s1,s2,ss1,ss2,tmp;
int n,q,ans,id;
pair<string,string>m[200010];
int main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		m[i].key=s1;
		m[i].val=s2;
	}
	for(int z=1;z<=q;z++){
		ans=0;
		int l=-1,r=-1;
		cin>>s1>>s2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]&&(l==-1))l=r=i;
			else if(s1[i]!=s2[i])r=i;
		}
		ss1=s1.substr(l,r-l+1);
		ss2=s2.substr(l,r-l+1);
		//cout<<ss1<<endl;
		for(int i=1;i<=n;i++){
			id=m[i].key.find(ss1);
			if(id>-1){
				tmp=ss1;
				//cout<<id<<endl;
				//cout<<m[i].key<<endl;
				for(int j=0;j<(int)ss1.size();j++,id++){
					ss1[j]=m[i].val[id];
				}
				if(ss1==ss2)ans++;
				ss1=tmp;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
