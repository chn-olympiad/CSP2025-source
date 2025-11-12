#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N=2e5+5;
const ll P=131;

int n,q;
string s[N][2],t[N][2];

namespace sub1{
	bool f[1000005];
	void mian(){
		f[0]=true; 
		for(int i=1;i<=q;i++){
			int ans=0;
			if(t[i][0].size()!=t[i][1].size()){
				cout<<0<<"\n";
				continue;
			}
			int lt=t[i][0].size();
			
			for(int j=lt-1;j>=0;j++) f[lt-1-j+1]=(f[lt-1-j]&(t[i][0][j]==t[i][1][j]));
			
			for(int j=1;j<=n;j++){
				int ls=s[j][0].size();
				if(ls>lt) continue;
				ll hs1=0,hs2=0;
				for(auto c:s[j][0]) hs1=hs1*P+c;
				for(auto c:s[j][1]) hs2=hs2*P+c;
				ll hs3=0,hs4=0,bs=1;
				for(int k=0;k<=ls-1;k++) hs3=hs3*P+t[i][0][k],hs4=hs4*P+t[i][1][k];
				for(int k=1;k<=ls-1;k++) bs*=P;
				
				for(int k=0;k<=lt-1;k++){
					if(hs3==hs1&&hs4==hs2&&f[lt-1-(k+ls)+1]) ans++;
					if(k+ls>=lt||t[i][0][k]!=t[i][1][k]) break;
					hs3=hs3-bs*t[i][0][k];
					hs3=hs3*P+t[i][0][k+ls];
					hs4=hs4-bs*t[i][1][k];
					hs4=hs4*P+t[i][1][k+ls];
					
				}
			}
			cout<<ans<<"\n";
		}
	}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
}

namespace sub2{
	bool check(){
		for(int i=1;i<=n;i++){
			for(auto c:s[i][0]) if(c!='a'&&c!='b') return false;
			for(auto c:s[i][1]) if(c!='a'&&c!='b') return false;
			for(auto c:t[i][0]) if(c!='a'&&c!='b') return false;
			for(auto c:t[i][1]) if(c!='a'&&c!='b') return false;
		}
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(auto c:s[i][0])
				if(c=='b'){
					if(flag) return false;
					flag=true; 
				}
			flag=false;
			for(auto c:s[i][1])
				if(c=='b'){
					if(flag) return false;
					flag=true; 
				}
			flag=false;
			for(auto c:t[i][0])
				if(c=='b'){
					if(flag) return false;
					flag=true; 
				}
			flag=false;
			for(auto c:t[i][1])
				if(c=='b'){
					if(flag) return false;
					flag=true; 
				}
		}
		return true;
	}
	int m;
	struct node{
		int x,y,z;
		bool operator < (const node& b) const{
			if(x!=b.x) return x<b.x;
			if(y!=b.y) return y<b.y;
			return z<b.z;
		}
	}a[N];
	struct Node{
		int x,y,z,id,res;
		bool operator < (const Node& b) const{
			if(x!=b.x) return x<b.x;
			if(y!=b.y) return y<b.y;
			return z<b.z;
		}
	}b[N];
	int ans[N];
	bool vis[N];
	void mian(){
		for(int i=1;i<=n;i++){
			int x=0,y=0;
			int len=s[i][0].size();
			for(int j=0;j<len;j++) if(s[i][0][j]=='b'){x=j; break;}
			for(int j=0;j<len;j++) if(s[i][1][j]=='b'){y=j; break;}
			a[i]={x-y,x,len-x};
		}
		for(int i=1;i<=q;i++){
			int x=0,y=0;
			int len=t[i][0].size();
			if(len!=t[i][1].size()){
				vis[i]=true;
				continue;
			}
			for(int j=0;j<len;j++) if(t[i][0][j]=='b'){x=j; break;}
			for(int j=0;j<len;j++) if(t[i][1][j]=='b'){y=j; break;}
			b[++m]={x-y,x,len-x,i,0};
		}
		sort(a+1,a+n+1);
		sort(b+1,b+m+1);
		int ql=1,qr=1;
		for(int l=1;l<=n;l++){
			int r=l;
			while(r<n&&a[r+1].x==a[l].x) r++;
			
			while(ql<=m&&b[ql].x<a[l].x) ql++;
			if(ql==m+1) break; 
			if(b[ql].x>a[l].x){
				l=r;
				continue;
			}
			qr=ql;
			while(qr<m&&b[qr+1].x==a[l].x) qr++;
			
			int k=ql;
			for(int j=l;j<=r;j++){
				while(k<=qr&&b[k].y<a[j].y) k++;
				if(k>qr) break;
				for(int w=k;w<=qr;w++) if(a[j].z<=b[w].z) b[w].res++; 
			}
			
			l=r,ql=qr+1;
			if(ql==m+1) break;
		}
		
		for(int i=1;i<=m;i++) ans[b[i].id]=b[i].res;
		for(int i=1;i<=q;i++){
			if(vis[i]) cout<<0<<"\n";
			else cout<<ans[i]<<"\n";
		}
	}
}

int main(){
//	freopen("replace4.in","r",stdin);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	if(sub2::check()) sub2::mian();
	else sub1::mian();  
	return 0;
}
