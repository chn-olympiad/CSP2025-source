#include<bits/stdc++.h>
using namespace std;
//int f1;
const int maxn=5e6+5,pp=131,mod1=1e9+7,mod2=1e9+9;
int n,m,ch1[maxn][26],ch2[maxn][26],cnt1,cnt2,len;
vector<int>vt1[maxn],vt2[maxn];
string x,y;
int q,h;
void add1(int xx){
	int u=0;
	for(int i=1;i<=len;i++){
		if(!ch1[u][x[i]-'a']){
			ch1[u][x[i]-'a']=++cnt1;
		}
		u=ch1[u][x[i]-'a'];
	} 
	vt1[u].push_back(xx);
}
void add2(int xx){
	int u=0;
	for(int i=1;i<=len;i++){
		if(!ch2[u][x[i]-'a']){
			ch2[u][x[i]-'a']=++cnt2;
		}
		u=ch2[u][x[i]-'a'];
	} 
	vt2[u].push_back(xx);
}
int cx(int xx){
	int u1=0,u2=0,ans=0;
	for(int i=xx;i<=len;i++){
		if(!ch1[u1][x[i]-'a']){
			break;
		}
		if(!ch2[u1][y[i]-'a']){
			break;
		}
		u1=ch1[u1][x[i]-'a'];
		u2=ch2[u2][y[i]-'a'];
		if(i>=h-1){
			for(int i:vt1[u1]){
				for(int j:vt2[u2]){
					if(i==j){
						ans++;
					}
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
//	if(m!=-1){
		for(int i=1;i<=n;i++){
			cin>>x;
			len=x.size();
			x="#"+x;
			add1(i);
			cin>>x;
			len=x.size();
			x="#"+x;
			add2(i);
		}
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			len=x.size();
			int www=y.size();
			if(www!=len){
				cout<<"0\n";
			} 
			else{
//				cout<<i<<" "<<x<<" "<<y<<"++++++\n";
				x="#"+x;
				y="#"+y;
				int hx1=0,hx2=0,hy1=0,hy2=0,ans=0;
				h=len+1;
				q=0;
				for(int i=1;i<=len;i++){
					hx1=(1ll*hx1*pp+x[i]-'a'+1)%mod1;
					hx2=(1ll*hx2*pp+x[i]-'a'+1)%mod2;
					hy1=(1ll*hy1*pp+y[i]-'a'+1)%mod1;
					hy2=(1ll*hy2*pp+y[i]-'a'+1)%mod2;
					if(hx1==hy1&&hx2==hy2){
						q=i;
					}
					else{
						break;
					}
				}
				hx1=hx2=hy1=hy2=0;
				for(int i=len;i>=1;i--){
					hx1=(1ll*hx1*pp+x[i]-'a'+1)%mod1;
					hx2=(1ll*hx2*pp+x[i]-'a'+1)%mod2;
					hy1=(1ll*hy1*pp+y[i]-'a'+1)%mod1;
					hy2=(1ll*hy2*pp+y[i]-'a'+1)%mod2;					
					if(hx1==hy1&&hx2==hy2){
						h=i;
					}
					else{
						break;
					}
				}
				for(int i=1;i<=min(len,q+1);i++){
					ans+=cx(i);
//					cout<<i<<" "<<cx(i)<<"???????\n";
				}
//				cout<<q<<" "<<h<<")))+*&TTFRFJGHK\n";
				cout<<ans<<"\n";
			}
		} 
//		return 0;
//	}
	return 0;
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

5 6
aaa bbb 
aa bb
a b
aa ab
aaaa bbba 

a b
aa bb
aaa aba
aaaa bbba
aaaaa abbbb
aaaaaa aabbba
*/
