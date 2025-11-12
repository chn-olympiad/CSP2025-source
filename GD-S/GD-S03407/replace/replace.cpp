#include<bits/stdc++.h>
using namespace std;
constexpr int SIZE = 1<<21;
char in[SIZE],out[SIZE],*p1=in,*p2=in,*p3=out;
#define getc() (p1==p2&&(p2=(p1=in)+fread(in,1,SIZE,stdin),p1==p2)?EOF:*p1++)
#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
#define putc(ch) (p3==out?(flush()):0,*p3++=ch)
class Flush{
	public:~Flush(){
		flush();
	}
}_;
template<class T>
void read(T &x){
	x=0;char c = getc();int f=1;
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c = getc();
	}
	while(c>='0' && c<='9'){
		x = (x<<3)+(x<<1)+(c^48);
		c = getc();
	}
	x*=f;
}
template<typename T,typename ...Args>
void read(T &x,Args&... x1){
	read(x),read(x1...);
}
template<typename type>
void write(bool f,type x){
	short static sta[30];short top=0;
	if(x<0) putc('-'),x=-x;
	while(x || top==0) sta[++top] = x%10,x/=10;
	while(top--) putc(char(sta[top+1]^48));
	(f)?putc(' '):putc('\n');
}
template<typename type,typename ...Args>
void write(bool f,type x,Args... x1){
	write(f,x),write(f,x1...);
}
void reads(string &s){
	s = "";
	char c = getc();
	while(c<'a' && c>'z'){
		c = getc();
	}
	while(c>='a' && c<='z'){
		s+=c;
		c= getc();
	} 
}
namespace my_space{
	using ll = long long;
	constexpr int N = 2e5+50,maxn = 5e6+100;
	string s1[N],s2[N];
	int ch[maxn][26],nxt[maxn],tot=1,val[maxn],ans; 
	vector<int> op[maxn];
	void insert(string s,int id){
		int p = 1;
		for(auto c:s){
			int w = c-'a';
			if(!ch[p][w]){
				ch[p][w] = ++tot;
			}	
			p = ch[p][w];
		}
		op[p].push_back(id);
		val[p] = s.size();
	}
	void bfs(){
		for(int i=0;i<26;i++){
			ch[0][i] = 1;
		}
		nxt[1] = 0;
		queue<int> q;
		q.push(1);
		while(q.size()){
			int x= q.front();
			q.pop();
			for(int i=0;i<26;i++){
				if(ch[x][i]){
					q.push(ch[x][i]);
					int k =nxt[x];
					nxt[ch[x][i]] = ch[k][i];
				}
				else{
					ch[x][i] = ch[nxt[x]][i];
				}
			}
		}
	}
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			insert(s1[i],i);
		}
		bfs();
		for(int i=1;i<=q;i++){
			ans=0;
			string q1,q2;
			cin>>q1>>q2;
			int p = 1;
			for(int j=0;j<int(q1.size());j++){
				char c= q1[j];
				p = ch[p][c-'a'];
				int temp = p;
				while(temp>1){
					if(val[temp]){
						for(auto x:op[temp]){
							int l = j-val[temp]+1;
							string tmp = s2[x];
							if(l){
								tmp = q1.substr(0,l)+tmp;
							}
							if(int(q1.size())-j){
								tmp+=q1.substr(j+1,int(q1.size())-j);
							}
							if(tmp==q2){
								ans++;
							}
						} 
					}
					temp = nxt[temp];
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
int main(){
	return my_space::main();
}

