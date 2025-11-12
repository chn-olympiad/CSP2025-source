#include <bits/stdc++.h>
using namespace std;
int n,q,go[200010],ll[200010],rr[200010];
string sa[200010],sb[200010],x,y;
map<int,int> mm;
bool fl=1;
int tt(string ss){
	int sss=0,id;
	for(int i=0;i<ss.size();i++){
		if(ss[i]!='a'&&ss[i]!='b') return 0;
		if(ss[i]=='b') sss++,id=i;
	}
	if(sss!=1) return 0;
	return id+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
		int aa=tt(sa[i]),bb=tt(sb[i]);
		fl&=aa&&bb;
		aa--,bb--;
		if(fl) go[i]=bb-aa,ll[i]=aa,rr[i]=sa[i].size()-aa-1,mm[go[i]]++;
	}
	long long RP=n,ADD=q,timee=RP*ADD;
	bool kl=(timee>1e8);
	while(q--){
		cin>>x>>y;
		int xx=tt(x),yy=tt(y),ans=0;
		if(fl&&xx&&yy){
			xx--,yy--;
			if(kl){
				cout<<mm[yy-xx]<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				if(xx+go[i]==yy&&xx>=ll[i]&&xx+rr[i]<x.size()) ans++;
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
/*
16:40 有点恶心
17:06 不会!!! 
3 4
aba aab
aba baa
aab aba
ba ab
aaba abaa
ab ba
abaa aaba

完了要AFO了,T1 AC,T2 16???,T3 5???,T4 8???,完了,怎么这么难啊! 
*/
