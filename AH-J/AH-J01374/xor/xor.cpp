#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt;
int a[N];
bool flag=0;
int f(int a,int b){
	int ans=0;
	string x,y,z;
	if(!a) return b;
	if(!b) return a;
	while(a){
		x+=a%2+'0';
		a/=2;
	}
	while(b){
		y+=b%2+'0';
		b/=2;
	}
	int n=x.size(),m=y.size();
	if(n<m){
		for(int i=m-n;i<m;i++) x+='0';
	}else if(n>m){
		for(int i=n-m;i<n;i++) y+='0';
	}
	for(int i=max(n,m);i>=0;i--){
		if(x[i]!=y[i]) z+='1';
		else z+='0';
	}
	int w=1;
	for(int i=z.size()-1;i>=0;i--){
		ans+=(z[i]-'0')*w;
		w*=2;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=1;
		if(a[i]==1) cnt++;
	}
	if(!flag){
		if(k) cout<<cnt<<"\n";
		else cout<<cnt/2<<"\n";
		return 0;
	}else{
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=0;
				for(int c=i;c<=j;c++){
					x=f(x,a[c]);
				}
				if(x==k){
					cnt++;
					i=j;
					break;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
