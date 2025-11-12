// #define DEBG 1
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+35,maxlen=5e6+35;
const ll inf=1e18;

namespace IO{
    #define MAXBUFFSIZE (1<<20)
    char buff[MAXBUFFSIZE],*head=buff,*tail=buff;
    inline char gc(){
        #ifdef DEBG
            return getchar();
        #endif
        if(head==tail) head=buff,tail=head+fread(buff,1,MAXBUFFSIZE,stdin);
        return (head==tail)?(EOF):*(head++);
    }
    inline ll read(){
        ll res=0,tf=1;
        char c=gc();
        while(c<'0'||c>'9') tf*=(c=='-')?(-1):(1),c=gc();
        while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=gc();
        return res*tf;
    }
	inline void read(string &s){
		s.clear();
		char c=gc();
		while(c<'a'||c>'z') c=gc();
		while(c>='a'&&c<='z') s.push_back(c),c=gc();
	}
}
using namespace IO;

int n,q;
string s[maxn][2];
void input(){
	n=read();q=read();
	for(int i=1;i<=n;++i){
		read(s[i][0]);read(s[i][1]);
	}
}

const ll b1=131,b2=149;
const ll p1=998244353ll,p2=1145141923ll;
struct Hash{
	ll a,b;
	Hash(){}
	Hash(ll a,ll b):a(a),b(b){}
	inline void operator += (char c){
		a=((a*b1)+c)%p1;
		b=((b*b2)+c)%p2;
	}
	inline Hash operator - (Hash y){
		return Hash(a-y.a,b-y.b);
	}
	inline bool operator < (Hash y)const{
		return (a==y.a)?(b<y.b):(a<y.a);
	}
	inline bool operator == (Hash y)const{
		return (a==y.a)&&(b==y.b);
	}
	inline void print(){
		cout<<"["<<a<<","<<b<<"]\n";
	}
};

multiset<Hash> delta;

void calc_hash(){
	for(int i=1;i<=n;++i){
		int len=s[i][0].length();
		Hash from=Hash(0,0),to=Hash(0,0);
		// cout<<"key:"<<i<<endl;
		for(int j=0;j<len;++j){
			from+=s[i][0][j];
			to+=s[i][1][j];
			// from.print();
			// to.print();
			// cout<<"\n";
		}
		delta.insert(to-from);
	}
}


int len;
string t1,t2;
bool sameb[maxlen];
void calc_back(){
	memset(sameb,0,sizeof(bool)*(len+5));
	Hash a=Hash(0,0),b=Hash(0,0);
	for(int i=len-1;i>=0;--i){
		a+=t1[i];
		b+=t2[i];
		if(a==b) sameb[i]=1;
		else break;
	}
}

ll ans;
void solvesingle(){
	Hash a=Hash(0,0),b=Hash(0,0);
	for(int i=0;i<len;++i){
		a+=t1[i];	
		b+=t2[i];
		if(sameb[i+1]) ans+=delta.count(b-a);
	}
}


void reset();

void ask(){
	for(int i=1;i<=q;++i){
		read(t1);read(t2);
		len=t1.length();
		calc_back();//计算在i之后的所有位置是否一致
		solvesingle();
		printf("%lld\n",ans);
		reset();
	}
}

void reset(){
	ans=0;
}

int main(){
	#ifndef DEBG
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif

	input();
	calc_hash();
	ask();
    return 0;
}
