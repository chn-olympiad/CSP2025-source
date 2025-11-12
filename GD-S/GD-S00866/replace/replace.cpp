#include<bits/stdc++.h>
using namespace std;
long long a,b,m[200005],n[200005],o[200005],p[200005],m1[200005],n1[200005],o1[200005],q[200005],r[200005],s,t,u[200005];
string c,d,e[200005],f[200005],g[200005],h[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	q[0]=1;
	for(int i=1;i<=200000;i++){
		q[i]=q[i-1]*27;
	}
	for(int i=1;i<=a;i++){
		cin>>c>>d;
		int j=0,k=c.length()-1;
		while(c[j]==d[j]){
			j++;
		}
		while(c[k]==d[k]){
			k--;
		}
		m1[i]=j;
		n1[i]=k-j+1;
		o1[i]=c.length()-k-1;
		for(int l=j-1;l>=0;l--){
			m[i]=m[i]*27+c[l]-'a'+1;
		}
		for(int l=j;l<=k;l++){
			n[i]=n[i]*27+c[l]-'a'+1;
			o[i]=o[i]*27+d[l]-'a'+1;
		}
		for(int l=k+1;l<c.length();l++){
			p[i]=p[i]*27+c[l]-'a'+1;
		}
	}
	for(int i=1;i<=b;i++){
		cin>>c>>d;
		if(c.length()!=d.length()){
			cout<<0<<'\n';
			continue;
		}
		int j=0,k=c.length()-1;
		while(c[j]==d[j]){
			j++;
		}
		while(c[k]==d[k]){
			k--;
		}
		for(int l=j-1;l>=0;l--){
			r[j-l]=r[j-l-1]*27+c[l]-'a'+1;
		}
		for(int l=j;l<=k;l++){
			s=s*27+c[l]-'a'+1;
			t=t*27+d[l]-'a'+1;
		}
		for(int l=k+1;l<c.length();l++){
			u[l-k]=u[l-k-1]*27+c[l]-'a'+1;
		}
		int x=0;
		for(int l=1;l<=a;l++){
			if(s==n[l]&&t==o[l]&&r[m1[l]]==m[l]&&u[o1[l]]==p[l]){
				x++;
			}
		}
		cout<<x<<'\n';
		for(int l=j-1;l>=0;l--){
			r[j-l]=0;
		}
		for(int l=j;l<=k;l++){
			s=0;
			t=0;
		}
		for(int l=k+1;l<c.length();l++){
			u[l-k]=0;
		}
	}
	return 0;
}
