#include<cstdio>
#include<iostream>
#include<cstring>
const int maxN=2e5+10;
int n,q,ans[maxN];
std::string s[maxN][3],ques[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		std::cin>>s[i][1];
		std::cin>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		ques[1].clear();
		ques[2].clear();
		std::cin>>ques[1];
		std::cin>>ques[2];
		for(int j=1;j<=n;j++){
			for(int l=0;l+(int)s[j][1].size()-1<=(int)ques[1].size()-1;l++){
				for(int k=0;k<=(int)ques[1].size()-1;k++){
					if(k>=l&&k<=l+(int)s[j][1].size()-1) continue;
					if(ques[1][k]!=ques[2][k]) goto next;
				}
				for(int k=l;k<=l+(int)s[j][1].size()-1;k++) if(ques[1][k]!=s[j][1][k-l]) goto next;
				for(int k=l;k<=l+(int)s[j][1].size()-1;k++) if(ques[2][k]!=s[j][2][k-l]) goto next;
				ans[i]++;
				next:continue; 
			} 
		}
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
