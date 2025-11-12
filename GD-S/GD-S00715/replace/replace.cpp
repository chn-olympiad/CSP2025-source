#include<bits/stdc++.h>
using namespace std;
vector<int> k[200002];
string qa,qb,ent;
string sa[200002];
string sb[200002];
int n,q;
string getin(){
	string sx;
	char sc=getchar();
	while(!(sc>='a'&&sc<='z')) sc=getchar();
	while(sc>='a'&&sc<='z'){
		sx.push_back(sc);
		sc=getchar();
	}
	return sx;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		sa[i]=getin();
		k[i].push_back(-1);
		for(unsigned int t=1,ot=0;t<sa[i].size();t++){
			if(sa[i][t]==sa[i][ot]) k[i].push_back(ot++);
			else{
				k[i].push_back(k[i][ot]);
				ot=k[i][ot]+1;
			}
		}
		sb[i]=getin();
	}
	for(int i=1,ans=0;i<=q;i++,ans=0){
		qa=getin();
		qb=getin();
		if(qa.size()!=qb.size()){
			printf("0\n");
			continue;
		}
		for(int t=1;t<=n;t++){
			vector<int> ik;
			ik.push_back(-1);
			unsigned int j=0,ot=0;
			for(;j<qa.size()&&ot<sa[t].size();j++){
				if(qa[j]==sa[t][ot]) ik.push_back(k[t][ot++]);
				else{
					ik.push_back(k[t][ot]);
					ot=ik[ot]+1;
				}
			}
			if(ot!=sa[t].size()) continue;
			string inqa=qa;
			for(j-=sa[t].size(),ot=0;ot<sa[t].size();j++,ot++) inqa[j]=sb[t][ot];
			if(inqa==qb) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
