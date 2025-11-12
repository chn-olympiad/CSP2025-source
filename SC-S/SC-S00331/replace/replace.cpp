#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	char c=getchar();x=0;
	int fh=1;
	while('0'>c||c>'9'){
		if(c=='-') fh*=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9') x=x*10-48+c,c=getchar();
	x*=fh;
}
void write(int x){
	if(x<0) {
		putchar('-');
		x*=-1;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=2e5+5;
int n,T,ans;
struct NODE{
	string s1,s2;
	int cd;
}a[N];
string s,ks[N],t1,t2,js[N];
bool cmp(NODE x,NODE y){return x.cd<y.cd;}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].cd=a[i].s1.size();
	}
	sort(a+1,a+n+1,cmp);
	while(T--) {
		ans=0;
		cin>>t1>>t2;
		t1=" "+t1;t2=" "+t2;
		int len=t1.size();
		if(len!=t2.size()) {
			cout<<0<<'\n';
			continue;
		}
		--len;
		string st="";
		for(int i=1;i<=len;i++)ks[i]=(st+=t1[i]);
		st="";
		for(int i=len;i>=1;i--)js[i]=(st=t1[i]+st);
		for(int i=1;i<=len;i++){
			for(int j=1;j<=n;j++){
//				cout<<i+a[j].cd<<'\n';
				if(i+a[j].cd>len) break;
//				cout<<j<<' '<<t1.substr(i+1,a[j].cd)<<' '<<a[j].s1<<'\n';
				if(t1.substr(i+1,a[j].cd)!=a[j].s1)continue;
//				cout<<j<<':'<<ks[i]<<a[j].s2<<js[i+a[j].cd+1]<<t2<<'\n';
				if(" "+ks[i]+a[j].s2+js[i+a[j].cd+1]==t2) ++ans; 
			}
		}
		for(int i=1;i<=n;i++){
			if(" "+a[i].s1==t1) {
				if(" "+a[i].s2==t2)++ans;
			}
		}
		if(t1==t2) ++ans;
		cout<<ans<<'\n';
	}
	return 0;
}