#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5,L=5e6+5;
int n,q,len[M],ls[M],lt[M],rs[M],rt[M],ans[M],t[L];
vector<char> s1[M],s2[M],t1[M],t2[M];
//char c[M];
void add(int x,int y){
	x++;
	while(x<L){
//		cout<<x<<endl;
		t[x]+=y;
		x+=(x&(-x));
	}
}
int get(int x){
	x++;
	int res=0;
	while(x){
		res+=t[x];
		x-=(x&(-x));
	}
	return res;
}
vector<pair<int,int> > pa[L],pb[L];
struct node{
	int l,r,id;
};
vector<node> na[L],nb[L];
const bool cmp(const node &ss1,const node &ss2){
	return (ss1.l==ss2.l)?(ss1.r<ss2.r):(ss1.l<ss2.l);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	char c=getchar();
	int suma,sumb;
	bool flagab=true;
	for(int i=1;i<=n;++i){
		c=getchar();
		suma=0,sumb=0;
		while(c<='z'&&c>='a'){
			s1[i].push_back(c);
			if(c=='a')suma++;
			if(c=='b')sumb++;
			c=getchar();	
		}
		if(suma+sumb!=s1[i].size()||sumb!=1)flagab=false;
		c=getchar();
		suma=0,sumb=0;
		while(c<='z'&&c>='a'){
			s2[i].push_back(c);
			if(c=='a')suma++;
			if(c=='b')sumb++;
			c=getchar();
		}
		if(suma+sumb!=s1[i].size()||sumb!=1)flagab=false;
		ls[i]=-1;
		for(int j=0;j<s1[i].size();++j){
			if(s1[i][j]!=s2[i][j]){
				rs[i]=j;
				if(ls[i]==-1)ls[i]=j;
			}
		}
//		for(int j=1;j<=strlen(c);++j)cout<<"s1[i][j]"<<s1[i][j]<<endl;
	}
	for(int i=1;i<=q;++i){
		c=getchar();
		suma=0,sumb=0;
		while(c<='z'&&c>='a'){
			t1[i].push_back(c);
			if(c=='a')suma++;
			if(c=='b')sumb++;
			c=getchar();	
		}
		if(suma+sumb!=s1[i].size()||sumb!=1)flagab=false;
		c=getchar();
		suma=0,sumb=0;
		while(c<='z'&&c>='a'){
			t2[i].push_back(c);
			if(c=='a')suma++;
			if(c=='b')sumb++;
			c=getchar();
		}
		if(suma+sumb!=s1[i].size()||sumb!=1)flagab=false;
		lt[i]=-1;
		for(int j=0;j<t1[i].size();++j){
			if(t1[i][j]!=t2[i][j]){
				rt[i]=j;
				if(lt[i]==-1)lt[i]=j;
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<s1[i].size();++j)cout<<s1[i][j];
//		cout<<endl;
//		for(int j=0;j<s2[i].size();++j)cout<<s2[i][j];
//		cout<<endl;
//		cout<<ls[i]<<' '<<rs[i]<<endl;
//	}
//	for(int i=1;i<=q;++i){
//		for(int j=0;j<t1[i].size();++j)cout<<t1[i][j];
//		cout<<endl;
//		for(int j=0;j<t2[i].size();++j)cout<<t2[i][j];
//		cout<<endl;
//		cout<<lt[i]<<' '<<rt[i]<<endl;
//	}
	if(!flagab){
		for(int i=1;i<=q;++i){
			for(int j=1;j<=n;++j){
				if(ls[j]==-1)continue;
//				cout<<lt[i]<<' '
				if(rt[i]-lt[i]==rs[j]-ls[j]&&lt[i]>=ls[j]&&t1[i].size()-1+ls[j]-lt[i]>=s1[j].size()-1){
//					cout<<"YES"<<i<<' '<<j<<' '<<-ls[j]<<' '<<s1[j].size()-ls[j]<<endl;
					bool flag=true;
					for(int k=0;k<s1[j].size();++k){
//						cout<<i<<' '<<j<<" "<<k<<" "<<k-ls[j]+lt[i]<<' '<<k<<endl;
						if(t1[i][k-ls[j]+lt[i]]!=s1[j][k]||t2[i][k-ls[j]+lt[i]]!=s2[j][k]){
							flag=false;
							break;
						}
					}
					if(flag)ans[i]++;
				}
			}
			printf("%d\n",ans[i]);
		}
	}else{
//		cout<<"IN"<<endl;
		for(int i=1;i<=n;++i){
			if(ls[i]==-1)continue;
			if(s1[i][ls[i]]=='a')pa[rs[i]-ls[i]].push_back(make_pair(ls[i]-1,s1[i].size()-rs[i]-1));
			else pb[rs[i]-ls[i]].push_back(make_pair(ls[i]-1,s1[i].size()-rs[i]-1));
		}
		for(int i=1;i<=q;++i){
			node kk;
			kk.l=lt[i]-1,kk.r=t1[i].size()-rt[i]-1,kk.id=i;
			if(t1[i][lt[i]]=='a'){
				na[rt[i]-lt[i]].push_back(kk);
			}else{
				nb[rt[i]-lt[i]].push_back(kk);
			}
		}
//		cout<<"DONE"<<endl;
		for(int i=0;i<L;++i){
			if(na[i].size()){
//				cout<<i<<endl;
				sort(na[i].begin(),na[i].end(),cmp);
				sort(pa[i].begin(),pa[i].end());
//				cout<<"SORTdone"<<endl;
				int nw=0;
				for(int j=0;j<na[i].size();++j){
//					cout<<j<<endl;
					while(nw<pa[i].size()&&pa[i][nw].first<=na[i][j].l){
//						cout<<"ADD"<<' '<<pa[i][nw].second<<endl;
						add(pa[i][nw].second,1);
//						cout<<"ADDDONE"<<endl;
						nw++;
					}
					ans[na[i][j].id]+=get(na[i][j].r);
				}
				for(int j=0;j<nw;++j){
					add(pa[i][j].second,-1);
				}
			}
			if(nb[i].size()){
//				cout<<i<<endl;
				sort(nb[i].begin(),nb[i].end(),cmp);
				sort(pb[i].begin(),pb[i].end());
//				cout<<"SORTdone"<<endl;
				int nw=0;
				for(int j=0;j<nb[i].size();++j){
//					cout<<j<<endl;
					while(nw<pb[i].size()&&pb[i][nw].first<=nb[i][j].l){
//						cout<<"ADD"<<' '<<pb[i][nw].second<<endl;
						add(pb[i][nw].second,1);
//						cout<<"ADDDONE"<<endl;
						nw++;
					}
					ans[nb[i][j].id]+=get(nb[i][j].r);
				}
				for(int j=0;j<nw;++j){
					add(pb[i][j].second,-1);
				}
			}
		}
		for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	}
	return 0;
}
/*
4 2
aba aab
aaaba aaaab
abaa aaba
aaba abaa
aabaa aaaba
aaaba aabaa
*/

