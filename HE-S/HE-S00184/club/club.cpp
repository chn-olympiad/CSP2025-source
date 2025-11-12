#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0;short f=1;char s=getchar();
	while(s<48||s>57){f=s=='-'?-1:1;s=getchar();}
	while(s>47&&s<58){x=x*10+(s&15);s=getchar();}
	return x*f;
}
const int N=1e5+5;
int n,pos,pos1,pos2,a[N][3],tot,tmp;
vector<pair<int,int>>e[3];ll sum,spos;
bool cmp(pair<int,int>x,pair<int,int>y){
	return
//	x.first!=y.first?x.first<y.first:
/*
...Huh?
Big samples was all cleared...After I delete this sentence...
But...Why?
*/
		x.first-max(a[x.second][pos1],a[x.second][pos2])>
		y.first-max(a[y.second][pos1],a[y.second][pos2]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T=read();
	while(T--){
		n=read();sum=0;pos=-1;
		for(int i=0;i<3;++i){
			e[i].clear();
			e[i].shrink_to_fit();
		}
		for(int i=1,mxn;i<=n;++i){
			mxn=0;
			for(int j=0;j<3;++j){
				a[i][j]=read();
				mxn=max(mxn,a[i][j]);
			}
			if(mxn==a[i][0])e[0].emplace_back(a[i][0],i);
			else if(mxn==a[i][1])e[1].emplace_back(a[i][1],i);
			else e[2].emplace_back(a[i][2],i);
		}
		for(int i=0;i<3;++i)if(e[i].size()>(n>>1)){pos=i;break;}
		if(!~pos){
			for(int i=0;i<3;++i)
				for(auto j:e[i])
					sum=sum+j.first;
			printf("%lld\n",sum);
			continue;
		}
		pos1=-1;pos2=-1;spos=0;
		tmp=e[pos].size();tot=tmp-1-(n>>1);
		for(int i=0;i<3;++i)
			if(i!=pos){if(!~pos1)pos1=i;else pos2=i;}
		sort(e[pos].begin(),e[pos].end(),cmp);
//		puts("-----------------------------------");//
//		for(auto i:e[pos])cout<<i.first<<' '<<i.second<<'\n';//
//		puts("-----------------------------------");//
		for(auto i:e[pos1])sum=sum+i.first;
		for(auto i:e[pos2])sum=sum+i.first;
		for(int i=tmp-1;i>tot;--i)spos=spos+e[pos][i].first;
//		cout<<"sum:"<<sum<<" spos:"<<spos<<'\n';//
		for(int i=tmp-1,fl=1,cnt;~i;--i){
			cnt=max(a[e[pos][i].second][pos1],a[e[pos][i].second][pos2]);
			if((fl?e[pos][tot].first:0)+cnt-e[pos][i].first>0){
				spos=spos-e[pos][i].first+(fl?e[pos][tot].first:0);
				sum=sum+cnt;--tmp;if(tot)--tot;else fl=0;
//				cout<<"sum:"<<sum<<" spos:"<<spos<<" i:"<<e[pos][i].second<<'\n';//
				e[pos].erase(e[pos].begin()+i);
			}
			if(!fl||tmp<=(n>>1))break;
		}
		if(tmp>(n>>1))
			for(int i=tot-1;~i;--i)
				sum=sum+max(a[e[pos][i].second][pos1],a[e[pos][i].second][pos2]);
		printf("%lld\n",sum+spos);
	}
	return 0;
}//Usami Sumireko,Violet_Detector
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
//It troubled me 2 hours.Time isn't enough.
//Hopes examples aren't waterful or datas are waterful...
