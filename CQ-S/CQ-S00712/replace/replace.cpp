#include<bits/stdc++.h>
using namespace std;

int n,q;
pair<string,string> p[100005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i){
		string s1,s2;
		cin>>s1>>s2;
		p[i]={s1,s2};
	}
	for(int i=1;i<=q;++i){
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int j=1;j<=n;++j){
			int f1=s1.find(p[j].first);
			int f2=s2.find(p[j].second);
			if(f1+1 && f2+1 && f1==f2){
				bool temp=1;
				for(int k=0;k<n;++k){
					if(k>=f1 && k<=f1+p[i].first.size()-1) continue;
					if(s1[k]!=s2[k]){temp=0;break;}
				}
				if(temp)++cnt;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
