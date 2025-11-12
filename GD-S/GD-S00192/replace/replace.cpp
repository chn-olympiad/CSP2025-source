#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
const int maxn=5e6+100;
const int N=2e5+10;
int n,q,len[N];
string s[N][2],t[N][2];
int ans[N];
map<int,int> mp;
struct node{
	int l,r,op;
};
bool cmp(node a,node b){
	if (a.r==b.r)return a.op<b.op;
	return a.r<b.r;
}
int tr[maxn];
void add(int x,int b){
	for (int i=x;i<maxn;i+=i&(-i))tr[i]+=b;
}
int query(int x){
	int res=0;
	for (int i=x;i;i-=i&-i)res=res+tr[i];
	return res;
}
vector<node> a[N];
void work(){
	cin>>n>>q;
	int sum=0,sum2=0;;
	for (int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		len[i]=s[i][0].size();
		sum+=s[i][0].size();
	}
	for (int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
		sum2+=t[i][0].size();
	}
	if (sum*sum2*4<=100000000){
		int res=0;
		for (int i=1;i<=q;i++){
			res=0;
			if(t[i][0].size()!=t[i][1].size()){
				cout<<0<<'\n';
				continue;
			} 
			int l=t[i][0].size();
			int x=l+1,y=0;
			for (int p=0;p<l;p++){
				if (t[i][0][p]!=t[i][1][p]){x=p;
					break;
				}
			}
			for (int p=l-1;p>=0;p--){
				if (t[i][0][p]!=t[i][1][p]){y=p;
					break;
				}
			}
			for (int j=0;j<l;j++){
				for (int k=1;k<=n;k++){
					if (j+len[k]-1<l&&j<=x&&j+len[k]-1>=y){
						bool fl=1;
						for (int p=j,x=0;p<=j+len[k]-1;p++,x++){
							if (t[i][0][p]!=s[k][0][x]||t[i][1][p]!=s[k][1][x]){
								fl=0;break;
							}
						}
						res+=fl;
					}
				}
			}
			cout<<res<<'\n';
		}
		return ;
	}
	else{
		int tt=0;
		for (int i=1;i<=n;i++){
			int x=0,y=0,yy=len[i]-1;
			for (int j=0;j<len[i];j++){
				if (s[i][0][j]=='b'){x=j;break;}
			}
			for (int j=len[i]-1;j>=0;j--){
				if (s[i][0][j]=='b'){yy=j;break;}
			}
			yy=len[i]-1-yy+1;
			for (int j=0;j<len[i];j++){
				if (s[i][1][j]=='b'){y=j;break;}
			}
			if (!mp[y-x])mp[y-x]=++tt;
			a[mp[y-x]].push_back((node){x+1,yy,0});
//			cout<<x<<' '<<y-x<<' '<<yy<<'\n';
			
		}
//		cout<<'\n';
		for (int i=1;i<=q;i++){
			len[i]=t[i][0].size();
			if(t[i][0].size()!=t[i][1].size()){
				continue;
			} 
			int x=0,y=0,yy=len[i]-1;
			for (int j=0;j<len[i];j++){
				if (t[i][0][j]=='b'){x=j;break;}
			}
			for (int j=len[i]-1;j>=0;j--){
				if (t[i][0][j]=='b'){yy=j;break;}
			}
			yy=len[i]-1-yy+1;
			for (int j=0;j<len[i];j++){
				if (t[i][1][j]=='b'){y=j;break;}
			}
//			cout<<x<<' '<<y-x<<' '<<yy<<'\n';
			if (!mp[y-x]){ans[i]=0;}
			else a[mp[y-x]].push_back((node){x+1,yy,i});
		}
//		cout<<'\n';
		for (int i=1;i<=tt;i++){
			sort(a[i].begin(),a[i].end(),cmp);
			for (int j=0;j<(int)a[i].size();j++){
//				cout<<a[i][j].l<<' '<<a[i][j].r<<' '<<a[i][j].op<<'\n';
				if (a[i][j].op==0){
					add(a[i][j].l,1);
				}
				else ans[a[i][j].op]=query(a[i][j].l);
			}
////			cout<<'\n';
			for (int j=0;j<(int)a[i].size();j++){
				if (a[i][j].op==0){
					add(a[i][j].l,-1);
				}
			}
		} 
		for (int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	}
}
signed main(){
//	system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while (t--){work();}
	return 0;
}
/*
3 3
ab ba
aba aab
aab aba
aba aab
aab aba
ab ba

*/
