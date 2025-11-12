#include<bits/stdc++.h>
#define MAXN 5010000
#define ull unsigned long long
using namespace std;
namespace Aleister{
	int n,q;
	char s1[MAXN],s2[MAXN];
	const ull base1=23,base2=37;
	ull tab1[MAXN],tab2[MAXN];
	int len;
	map<pair<pair<ull,ull>,pair<ull,ull> >,int>mp;
	ull s1p1[MAXN],s1p2[MAXN],s2p1[MAXN],s2p2[MAXN];
	bool hvlen[MAXN];
	int polen[210000],cnt;
	pair<ull,ull> hash1(int l,int r){if(l>r) return make_pair(114514,114514); return make_pair(s1p1[r]-s1p1[l-1]*tab1[r-l+1],s1p2[r]-s1p2[l-1]*tab2[r-l+1]);}
	pair<ull,ull> hash2(int l,int r){if(l>r) return make_pair(114514,114514); return make_pair(s2p1[r]-s2p1[l-1]*tab1[r-l+1],s2p2[r]-s2p2[l-1]*tab2[r-l+1]);}
	int ans;
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++){
			scanf("%s%s",s1+1,s2+1),len=strlen(s1+1);
			if(!hvlen[len]) hvlen[len]=1,polen[++cnt]=len;
			ull x1=0,x2=0,y1=0,y2=0;
			for(int j=1;j<=len;j++){
				x1*=base1,x1+=s1[j],x2*=base2,x2+=s1[j];
				y1*=base1,y1+=s2[j],y2*=base2,y2+=s2[j];
			}
			mp[make_pair(make_pair(x1,x2),make_pair(y1,y2))]++;
//			cerr<<x1<<' '<<x2<<"  "<<y1<<' '<<y2<<'\n';
		}
		sort(polen+1,polen+1+cnt);
		for(int i=1;i<=q;i++){
			scanf("%s%s",s1+1,s2+1),len=strlen(s1+1);
			tab1[0]=tab2[0]=1,ans=0;
			for(int j=1;j<=len;j++){
				tab1[j]=tab1[j-1]*base1,tab2[j]=tab2[j-1]*base2;
				s1p1[j]=s1p1[j-1]*base1+s1[j],s1p2[j]=s1p2[j-1]*base2+s1[j];
				s2p1[j]=s2p1[j-1]*base1+s2[j],s2p2[j]=s2p2[j-1]*base2+s2[j];
			}
			for(int id=1;id<=cnt;id++){
				int nowlen=polen[id];
//				cerr<<"@@@"<<nowlen<<'\n';
				for(int j=1;j+nowlen-1<=len;j++){
					if(hash1(1,j-1)!=hash2(1,j-1)||hash1(j+nowlen,len)!=hash2(j+nowlen,len)) continue;
					pair<ull,ull>p1=hash1(j,j+nowlen-1),p2=hash2(j,j+nowlen-1);
//					cerr<<j<<' '<<j+nowlen-1<<"   "<<p1.first<<' '<<p1.second<<"  "<<p2.first<<' '<<p2.second<<'\n';
					ans+=mp[make_pair(p1,p2)];
				}
			}
			printf("%d\n",ans);
		}
		return 0;
	}
}
int main(){
	return Aleister::main();
}
//20cm什么的真的不行啊!~~ 
