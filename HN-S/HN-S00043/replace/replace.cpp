#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
const int M=2e5+5;
int n,m,cnt,tot;
char a[N*2];
int f[N*3][27];
int ti[N*3],kmp[N*3];
queue<int> q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	string x,y;
    	cin>>x>>y;
    	if(x==y) continue;
    	int len=x.size();
    	int mi=0,mi2=len-1;
    	for(int j=0;j<len;j++){
    		if(x[j]==y[j]) mi=j+1;
    		else break;
		}
		for(int j=len-1;j+1;j--){
    		if(x[j]==y[j]) mi2=j-1;
    		else break;
		}
		tot=0;
		for(int j=0;j<mi;j++) a[++tot]=x[j];
		a[++tot]='z'+1;
		for(int j=mi;j<=mi2;j++) a[++tot]=x[j];
		a[++tot]='z'+1;
		for(int j=mi;j<=mi2;j++) a[++tot]=y[j];
		a[++tot]='z'+1;
		mi2++;
		for(;mi2<len;mi2++) a[++tot]=x[mi2];
		int fa=0;
		for(int j=1;j<=tot;j++){
			if(!f[fa][a[j]-'a']) f[fa][a[j]-'a']=++cnt;
			fa=f[fa][a[j]-'a'];
		}
		ti[fa]++;
	}
	for(int i=1;i<=m;i++){
		string x,y;
    	cin>>x>>y;
    	if(x==y) continue;
    	int len=x.size();
    	int mi=0,mi2=len-1;
    	for(int j=0;j<len;j++){
    		if(x[j]==y[j]) mi=j+1;
    		else break;
		}
		for(int j=len-1;j+1;j--){
    		if(x[j]==y[j]) mi2=j-1;
    		else break;
		}
		tot=0;
		for(int j=0;j<mi;j++) a[++tot]=x[j];
		a[++tot]='z'+1;
		for(int j=mi;j<=mi2;j++) a[++tot]=x[j];
		a[++tot]='z'+1;
		for(int j=mi;j<=mi2;j++) a[++tot]=y[j];
		a[++tot]='z'+1;
		mi2++;
		for(;mi2<len;mi2++) a[++tot]=x[mi2];
		int fa=0,sum=0;
		for(int j=1;j<=tot;j++){
			fa=0;
			for(int k=j;k<=tot;k++){
				if(!f[fa][a[k]-'a']) break;
				fa=f[fa][a[k]-'a'];
				sum+=ti[fa];
			}
		}
		cout<<sum<<"\n";
	}
}




