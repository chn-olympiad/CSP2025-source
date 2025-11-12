#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=(1LL<<60);
const int N=1e5+7;
struct node{
	int id,v;
	bool operator<(const node& x)const{
		return v>x.v;
	}
}tt[5];
struct peaple{
	int c[5],id[5];
	int cur;
	void fit(){
		for(int i=1;i<=3;i++) tt[i].id=i,tt[i].v=c[i];
		sort(tt+1,tt+1+3);
		for(int i=1;i<=3;i++) id[i]=tt[i].id;
		cur=1;
	}
	int chose(){
		if(cur<=3) return id[cur];
		else return 0;
	}
	int get(){
		if(cur<=3) return c[id[cur]];
		else return -inf;
	}
	int nxtval(){
		if(cur==3) return inf;
		else return c[id[cur]]-c[id[cur+1]];
	}
	void nxt(){
		if(cur==4) return;
		else cur++;
	}
}p[N];
vector<int>p1;
vector<int>p2;
vector<int>p3;
int n;

struct temp{
	int d,id;
	bool operator<(const temp& x)const{
		return d>x.d;
	}
}tmp[N];
void fit(int x){
	if(x==1){
		int len=p1.size();
		for(int i=0;i<len;i++){
			int id=p1[i];
			tmp[i+1].d=p[id].nxtval();
			tmp[i+1].id=id;
		}
		sort(tmp+1,tmp+1+len);
		p1.clear();
		for(int i=1;i<=n/2;i++){
			p1.push_back(tmp[i].id);
		}
		for(int i=n/2+1;i<=len;i++){
			int id=tmp[i].id;
			p[id].nxt();
			if(p[id].chose()==1) p1.push_back(id);
			if(p[id].chose()==2) p2.push_back(id);
			if(p[id].chose()==3) p3.push_back(id);
		}
	}
	if(x==2){
		int len=p2.size();
		for(int i=0;i<len;i++){
			int id=p2[i];
			tmp[i+1].d=p[id].nxtval();
			tmp[i+1].id=id;
		}
		sort(tmp+1,tmp+1+len);
		p2.clear();
		for(int i=1;i<=n/2;i++){
			p2.push_back(tmp[i].id);
		}
		for(int i=n/2+1;i<=len;i++){
			int id=tmp[i].id;
			p[id].nxt();
			if(p[id].chose()==1) p1.push_back(id);
			if(p[id].chose()==2) p2.push_back(id);
			if(p[id].chose()==3) p3.push_back(id);
		}
	}
	if(x==3){
		int len=p3.size();
		for(int i=0;i<len;i++){
			int id=p3[i];
			tmp[i+1].d=p[id].nxtval();
			tmp[i+1].id=id;
		}
		sort(tmp+1,tmp+1+len);
		p3.clear();
		for(int i=1;i<=n/2;i++){
			p3.push_back(tmp[i].id);
		}
		for(int i=n/2+1;i<=len;i++){
			int id=tmp[i].id;
			p[id].nxt();
			if(p[id].chose()==1) p1.push_back(id);
			if(p[id].chose()==2) p2.push_back(id);
			if(p[id].chose()==3) p3.push_back(id);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		p1.clear();
		p2.clear();
		p3.clear();
		for(int i=1;i<=n;i++){
			cin>>p[i].c[1]>>p[i].c[2]>>p[i].c[3];
			p[i].fit();
			if(p[i].chose()==1) p1.push_back(i);
			if(p[i].chose()==2) p2.push_back(i);
			if(p[i].chose()==3) p3.push_back(i);
		}
		while(p1.size()>n/2||p2.size()>n/2||p3.size()>n/2){
			if(p1.size()>n/2) fit(1);
			if(p2.size()>n/2) fit(2);
			if(p3.size()>n/2) fit(3);
		}
		int res=0;
		for(auto i:p1) res=res+p[i].c[1];
		for(auto i:p2) res=res+p[i].c[2];
		for(auto i:p3) res=res+p[i].c[3];
		cout<<res<<"\n";
	}
	return 0;
}
