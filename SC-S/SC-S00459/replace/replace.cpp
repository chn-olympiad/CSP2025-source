#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=200+5,hsh=239;
int n,q;
map<ull,ull>mp;
ull f(ull a,int b){
	ull z=1;
	while(b){
		if(b&1)z=a*z;
		a=a*a;
		b>>=1;
	}return z;
}
ull gt(string x){
	ull as=0,tt=hsh;
	for(int i=0;i<x.size();i++){
		as=as+int(x[i]+1-'a')*tt;
		tt*=hsh;
//		cout<<as<<" "; 
	}
//	cout<<'\n';
	return as;
}
ull hh[N][2],tt[N][2];
ull gtt(int l,int r,int oo){
	return (hh[r][oo]-hh[l-1][oo])/tt[l-1][oo];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a, b;
		cin>>a>>b;
		mp[gt(a)]=gt(b);
//		cout<<a<<" "<<gt(a)<<'\n';
	}
	for(int i=1;i<=q;i++){
		string a, b;
		cin>>a>>b;
		a=' '+a;
		b=' '+b;
		if(a.size()!=b.size()){
			cout<<0<<'\n';
			continue;
		}
		int oo=0;
		tt[0][oo]=1;
		for(int j=1;j<a.size();j++){
			tt[j][oo]=tt[j-1][oo]*hsh;
			hh[j][oo]=hh[j-1][oo]+int(a[j]+1-'a')*tt[j][oo];
//			cout<<hh[j][0]<<' ';
//			cout<<a[j];
		}
//		cout<<hh[a.size()-1][0]<<'\n';
		oo=1;
		tt[0][oo]=1;
		for(int j=1;j<a.size();j++){
			tt[j][oo]=tt[j-1][oo]*hsh;
			hh[j][oo]=hh[j-1][oo]+int(b[j]+1-'a')*tt[j][oo];
		}
		int ans=0;
		for(int l=1;l<a.size();l++){
			for(int r=l;r<a.size();r++){
				ull op=mp[gtt(l,r,0)];
				if(op){
//					cout<<l<<" "<<r<<'\n';
					if(gtt(l,r,1)==op&&gtt(1,l-1,0)==gtt(1,l-1,1)&&gtt(r+1,a.size()-1,0)==gtt(r+1,a.size()-1,1)){
						ans++;
					}
				}
			}
		}cout<<ans<<'\n';
	}
	return 0;
} 