#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,bs,bt,bbb[5000006];
struct eyz{
	string s1,s2,sc1,sc2;
}ss[N],ts[N];
int bb(string x,string y){
	int xx,yy;
	for(int i=0;i<x.size();i++){
		if(x[i]=='b'){
			xx=i;
			break;
		}
	}
	for(int i=0;i<y.size();i++){
		if(y[i]=='b'){
			yy=i;
			break;
		}
	}
	return xx-yy+2500000;
}
bool check(string x,string y){
	if(x.size()<y.size()) return false;
	for(int i=0,j=0;i<x.size();i++){
		if(x[i]==y[j]) j++;
		else j=0;
		if(j==y.size()) return true;
	}
	return false;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	if(n>1000){
		for(int i=1;i<=n;i++){
			cin >> ss[i].s1 >> ss[i].s2;
			bs=bb(ss[i].s1,ss[i].s2);
			bbb[bs]++;
		}
		for(int i=1;i<=q;i++){
			int ans=0;
			cin >> ts[i].s1 >> ts[i].s2;
			bt=bb(ts[i].s1,ts[i].s2);
			ans+=bbb[bt];
			cout << ans << "\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> ss[i].s1 >> ss[i].s2;
		int len=ss[i].s1.size(),lef=-1,rig=-1;
		for(int j=0;j<len;j++){
			if(ss[i].s1[j]!=ss[i].s2[j]){
				if(lef==-1) lef=rig=j;
				else rig=j;
			}
		}
		for(int j=lef;j<=rig;j++){
			ss[i].sc1=ss[i].sc1+ss[i].s1[j];
			ss[i].sc2=ss[i].sc2+ss[i].s2[j];
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin >> ts[i].s1 >> ts[i].s2;
		string a1=ts[i].s1,a2=ts[i].s2,ac1,ac2;
		if(a1.size()!=a2.size()){
			cout << "0\n";
			continue;
		}
		int len=a1.size();
		int lef=-1,rig=-1;
		for(int j=0;j<len;j++){
			if(a1[j]!=a2[j]){
				if(lef==-1) lef=rig=j;
				else rig=j;
			}
		}
		for(int j=lef;j<=rig;j++){
			ac1=ac1+a1[j];
			ac2=ac2+a2[j];
		}
		for(int j=1;j<=n;j++){
			if(ac1==ss[j].sc1&&ac2==ss[j].sc2)
				if(check(a1,ss[j].s1)&&check(a2,ss[j].s2)) ans++;
		}
		//cout << ac1 << "==>" << ac2 << "\n";
		//cout << ss[1].sc1 << "==>" << ss[1].sc2 << "\n";
		cout << ans << "\n";
	}
	return 0;
}
