#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char ch=' ';
	int sum=0;
	while(!(ch>='0'&&ch<='9'))ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum;
}
int T,n,m;
int a[505],c[505],p[505];
bool used[15];
const int mod=998244353;
bool nxt(int id){//forget the name of next_pr*****()
	if(id>=10)return false;
	bool flag=false;
	for(int i=id;i<10;++i){
		if(p[i]<p[i+1]){
			flag=true;
			break;
		}
	} 
	if(flag==false)return false;
	used[p[id]]=true;
	if(nxt(id+1)==false){
		used[p[id]]=false;
		for(int j=p[id]+1;j<=10;++j){
			if(!used[j]){
				p[id]=j;
				used[j]=true;
				break;
			}
		}
		for(int j=id+1,k=1;k<=n;++k){
			if(!used[k]){
				p[j++]=k;
			}
		}
		used[p[id]]=false;
		return true;
	}
	used[p[id]]=false;
	return true;
}
int ans=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	bool flag=true;
	for(int i=1;i<=n;++i){
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		a[i]=ch-'0';
		if(a[i]=='0')flag=false;
	} 
	for(int i=1;i<=n;++i){
		c[i]=read();
		p[i]=i;
	}
	do{
		int cnt_broken=0;
		for(int i=1;i<=n;++i){
			if(cnt_broken>=c[p[i]]||a[i]==0){
				++cnt_broken;
				continue;
			}
		} 
		if(n-cnt_broken>=m){
			++ans;
			ans%=mod;
		}
	}while(nxt(1));
	cout<<ans;
} 
/*
Uid:753204 mywzj_mo
All in word,
bits\stdc++.h
//freopen
freeopen
freopen("employ.out","r",stdin)
freopen("employ.in","w",stdout)
int mian(){
cnt_broken=4;


Colin is a human in the game "Changed",
and there is a darklatex wolf named Puro.
oh,don't forget to introduce,the Doctor.K trys his/her best to transfur Colin.However,
Colin and Puro make friends and fight(?) with Doctor.K .
Colin is smart and /nameless word/,and Puro is brave and helpful.
Fighting(?) to all the difficulties,can they succees?Look forward to "Changed-special" by DragonSnow.
---A lover of furry and an oier's text on 2025CSP-S.---

So how can I do this problem?
I found O(n!).But it only can get 8pts.
No idea.
I'm going crazy.

My friend:XDB(Baned User),PuShuai(Not oier).
------They ask me to write them into the code.

*/
