#include<bits/stdc++.h>
#define N 200005
using namespace std;
/*
看着比较T2顺眼一点？我们来看一下哈
一股子 kmp 味道
首先对于每个询问，我们肯定是需要把他需要被替换的串找出来的
考虑用找出来的子串 KMP 去找可以替换的模式串
显然每个n都是一个，模式串，天，我们要跑好多个nxt出来 
先写吧，不会多的了
nmnmnmnmnmnmKMP写错了wssb 哈卵玩意儿 
顺眼个78顺眼 信 T3 顺眼不如信我是秦始皇 成功浪费2h 
特殊性质凭啥写不对nmlgb  
今天是最蠢的一天，和去年-s的分竟然差不多高 有意思不 
不如回去玩农玩原 
*/
string s[N][3],t,tt;//t[N][3];
int n,q,nxt[N][2],res[2],tot,st,en,L1,ju[N],zz[N],yy[N];
//void get_nxt(string b,int f){
//nm 就你写不对是吧 
//} 
void KMP(string a,string b,int f){
	tot=0;
	int lena=a.size()-1,lenb=b.size();
	b=" "+b;
	int k=0;
	for(int i=1;i<=lena;i++){
		while(k&&a[i]!=b[k+1]) k=nxt[k][f];
		if(a[i]==b[k+1]) k++;
		if(k==lenb){
			if(i-k+1<=st&&lenb+i-k>=en) res[f]=1;
			k=nxt[k][f];
		}
	}
} 
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2],L1+=(2*s[i][1].size());
	if(L1>2000){
		for(int i=1;i<=n;i++){
			int cy=0,yh=0;
			for(int k=0;k<s[i][1].size();k++) if(s[i][1][k]=='b'){cy=k;break;} 
			for(int k=0;k<s[i][2].size();k++) if(s[i][2][k]=='b'){yh=k;break;}
			ju[i]=yh-cy;zz[i]=max(cy,yh);
			yy[i]=max(s[i][1].size()-cy,s[i][1].size()-yh);
		}
		while(q--){
			cin>>t>>tt;
			if(t.size()!=tt.size()){
				cout<<0<<endl;continue;
			}
			int cy=0,yh=0,jul=0,ans=0;
			for(int k=0;k<t.size();k++) if(t[k]=='b'){cy=k;break;} 
			for(int k=0;k<tt.size();k++) if(tt[k]=='b'){yh=k;break;}
			jul=yh-cy;
			int ZZ=max(cy,yh),YY=max(t.size()-cy,t.size()-yh);
			for(int i=1;i<=n;i++){
				if(jul==ju[i]&&ZZ>=zz[i]&&YY>=yy[i]) ans++;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
	while(q--){
		cin>>t>>tt;
		int lent=t.size(),ans=0;
		if(lent!=tt.size()){cout<<"0"<<endl;continue;}
		t=" "+t,tt=" "+tt,tot=0,st=0,en=0;
		for(int i=1;i<=n;i++){
			if(t[i]!=tt[i]&&!st) st=i;
			else if(t[i]!=tt[i]) en=i;
			nxt[i][0]=nxt[i][1]=0;
		}
		if(en==0) en=st;
		for(int i=1;i<=n;i++){
			KMP(t,s[i][1],0);
			KMP(tt,s[i][2],1);
			if(res[0]&&res[1]) ans++;
			res[0]=res[1]=0;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
