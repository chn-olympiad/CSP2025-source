#include<bits/stdc++.h>
#define ull unsigned long long
#define qwe(i,l,r) for(int i=l;i<=r;++i)
#define ewq(i,l,r) for(int i=l;i>=r;--i)
#define mkp make_pair
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f=ch=='-'?-f:f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=5e6+5;
map<pair<ull,ull>,int>f;
int c[N][27],cnt,tot,top,rt[N],fai[N];
int n,q;
int v[N];
string s,s1;
int g(char x){
	if(x=='#')return 0;
	return x-96;
}
void add(int _rt,string _){
	int u=rt[_rt],len=_.size();
//	cout<<u<<' ';
	qwe(i,0,len-1){
		if(!c[u][g(_[i])])c[u][g(_[i])]=++cnt;
		u=c[u][g(_[i])];
//		cout<<u<<' ';
	}
//	cout<<'\n';
	++v[u];
}
void bfs(int _rt){
	queue<int>q;
	fai[rt[_rt]]=rt[_rt];
	q.push(rt[_rt]);
	while(!q.empty()){
		int u=q.front();q.pop();
//		if(_rt==1)printf("fai %d : %d\n",u,fai[u]);
		qwe(i,0,26){
			fai[c[u][i]]=rt[_rt];
			if(c[u][i]){
				q.push(c[u][i]);
				if(c[u][i]!=c[fai[u]][i]){
					fai[c[u][i]]=c[fai[u]][i];
					v[c[u][i]]+=v[c[fai[u]][i]];
				}
//				if(_rt==1)cout<<"fai"<<c[u][i]<<"="<<fai[u]
			}
			else c[u][i]=c[fai[u]][i];
		}
	}//cout<<'\n';
}
int Q(int _rt,string _){
	if(_rt==0)return 0;
	int u=rt[_rt],len=_.size(),ans=0;
//	cout<<_<<u<<_rt<<'\n';
	qwe(i,0,len-1){
		while(u!=fai[u]&&!c[u][g(_[i])]){
			u=fai[u];
//			if(q==27477)cout<<u<<'\n';
//			if(u==0)break;
		}
		if(c[u][g(_[i])])u=c[u][g(_[i])];
		ans+=v[u];
//		cout<<"askjd"<<u<<'\n';
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	qwe(i,1,n){
		cin>>s>>s1;
		int len=s.size();
		int l=-1,r;
		qwe(i,0,len-1)if(s[i]!=s1[i]){
			l=i;
			break;
		}
		ewq(i,len-1,0)if(s[i]!=s1[i]){
			r=i;
			break;
		}
		if(l==-1)continue;
		else{
			ull ans=0,ans1=0;
			string _="";
			qwe(i,l,r)ans=ans*37+s[i]-96;
			qwe(i,l,r)ans1=ans1*37+s1[i]-96;
			qwe(i,0,l-1)_+=s[i];
			_+='#';
			qwe(i,r+1,len-1)_+=s[i];
			if(f[mkp(ans,ans1)]==0){
				f[mkp(ans,ans1)]=++tot;
				rt[tot]=++cnt;
			}
			add(f[mkp(ans,ans1)],_);
//			cout<<_<<'\n';
		}
	}
	qwe(i,1,tot)bfs(i);
//	qwe(i,1,6)cout<<v[i]<<' ';cout<<'\n';
	while(q--){
		cin>>s>>s1;
		int len=s.size();
		int l=-1,r;
		qwe(i,0,len-1)if(s[i]!=s1[i]){
			l=i;
			break;
		}
		ewq(i,len-1,0)if(s[i]!=s1[i]){
			r=i;
			break;
		}
		ull ans=0,ans1=0;
		string _="";
		qwe(i,l,r)ans=ans*37+s[i]-96;
		qwe(i,l,r)ans1=ans1*37+s1[i]-96;
		qwe(i,0,l-1)_+=s[i];
		_+='#';
		qwe(i,r+1,len-1)_+=s[i];
//		return 0;
		int an=Q(f[mkp(ans,ans1)],_);
//		cout<<_<<'\n';
		cout<<an<<'\n';
	}
	return 0;
}
