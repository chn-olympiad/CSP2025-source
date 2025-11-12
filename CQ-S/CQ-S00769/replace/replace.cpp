#include<bits/stdc++.h>
using namespace std;
namespace estidi{
	const int ml=5600003;
	int root,cnt,sons[ml][29],fail[ml],adcnt[ml],qq[ml],qb,qf;
	void build(){
		for(int i=1;i<=27;i++)
			if(sons[0][i])
				qq[qb++]=sons[0][i];
		while(qb!=qf){//ACAM?
			int x=qq[qf++];
			for(int i=1;i<=27;i++)
				if(sons[x][i]){
					qq[qb++]=sons[x][i];
					int now=fail[x];
					while(sons[now][i]==0&&now)
						now=fail[now];
					if(sons[now][i])
						fail[sons[x][i]]=sons[now][i];
					adcnt[sons[x][i]]+=adcnt[fail[sons[x][i]]];
				}
		}
	}
	void read(string &s){
		s="";
		char c;
		while(1){
			c=getchar();
			if(c!=' '&&c!='\n'&&c!=EOF)
				break;
		}
		s+=c;
		while(1){
			c=getchar();
			if(c!=' '&&c!='\n'&&c!=EOF)
				s+=c;
			else
				break;
		}
	}
	int main(){
		int k,q;
		string s1,s2;
		scanf("%d%d",&k,&q);
		while(k--){
			read(s1);
			read(s2);
			int lp=0,rp=(int)s1.size()-1;
			while(lp<(int)s1.size()&&s1[lp]==s2[lp])
				lp++;
			if(lp==(int)s1.size())
				continue;
			while(rp&&s1[rp]==s2[rp])
				rp--;
			int now=root;
//			cerr<<s2<<" "<<endl;
			for(int i=0;i<(int)s1.size();i++){
				if(i==lp){
					if(!sons[now]['{'-'a'+1])
						sons[now]['{'-'a'+1]=++cnt;
					now=sons[now]['{'-'a'+1];
//					cerr<<"{";
				}
				if(!sons[now][s1[i]-'a'+1])
					sons[now][s1[i]-'a'+1]=++cnt;
				now=sons[now][s1[i]-'a'+1];
//				cerr<<s1[i];
				if(i==rp){
					if(!sons[now]['{'-'a'+1])
						sons[now]['{'-'a'+1]=++cnt;
					now=sons[now]['{'-'a'+1];
//					cerr<<"{";
					for(int j=lp;j<=rp;j++){
						if(!sons[now][s2[j]-'a'+1])
							sons[now][s2[j]-'a'+1]=++cnt;
						now=sons[now][s2[j]-'a'+1];
//						cerr<<s2[j];
					}
					if(!sons[now]['{'-'a'+1])
						sons[now]['{'-'a'+1]=++cnt;
					now=sons[now]['{'-'a'+1];
//					cerr<<"{";
				}
			}
//			cerr<<endl;
//			cerr<<rs<<endl;
			adcnt[now]++;
		}
		build();
		for(int nq=1;nq<=q;nq++){
			read(s1);
			read(s2);
			if(s1.size()!=s2.size()){
				printf("0\n");
				continue;
			}
			int lp=0,rp=(int)s1.size()-1;
			while(lp<(int)s1.size()&&s1[lp]==s2[lp])
				lp++;
			assert(lp!=(int)s1.size());
			while(rp&&s1[rp]==s2[rp])
				rp--;
			int now=root,ans=0;
			for(int i=0;i<(int)s1.size();i++){
				if(i==lp){
					while(sons[now]['{'-'a'+1]==0&&now)
						now=fail[now];
					if(sons[now]['{'-'a'+1])
						now=sons[now]['{'-'a'+1];
					ans+=adcnt[now];
//					if(nq==31)
//						cerr<<"{";
				}
				while(sons[now][s1[i]-'a'+1]==0&&now)
					now=fail[now];
				if(sons[now][s1[i]-'a'+1])
					now=sons[now][s1[i]-'a'+1];
				ans+=adcnt[now];
//				if(nq==31)
//					cerr<<s1[i];
				if(i==rp){
					while(sons[now]['{'-'a'+1]==0&&now)
						now=fail[now];
					if(sons[now]['{'-'a'+1])
						now=sons[now]['{'-'a'+1];
					ans+=adcnt[now];
//					if(nq==31)
//						cerr<<"{";
					for(int j=lp;j<=rp;j++){
						while(sons[now][s2[j]-'a'+1]==0&&now)
							now=fail[now];
						if(sons[now][s2[j]-'a'+1])
							now=sons[now][s2[j]-'a'+1];
						ans+=adcnt[now];
//						if(nq==31)
//							cerr<<s2[i];
					}
					while(sons[now]['{'-'a'+1]==0&&now)
						now=fail[now];
					if(sons[now]['{'-'a'+1])
						now=sons[now]['{'-'a'+1];
					ans+=adcnt[now];
//					if(nq==31)
//						cerr<<"{";
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	estidi::main();
	return 0;
}
//664MB
