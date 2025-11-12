#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,fb,z[200001];
struct ox{string a,b;ll l,r,len;}; 
ox s[200001],t[200001];
ox s1[200001],s2[200001];
ll cmp(ox a,ox b){
	if(a.r-a.l==b.r-b.l) {
		if(a.l==b.l) a.r>b.r;
		else return a.l<b.l;
	}
	else return a.r-a.l<b.r-b.l;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].len=s[i].a.length();
		for(ll j=0;j<s[i].len;j++)
			if(s[i].a[j]!=s[i].b[j]) {s[i].l=j;break;}
		for(ll j=s[i].len;j>=0;j--)
			if(s[i].a[j]!=s[i].b[j]) {s[i].r=j;break;}
	}
	for(ll i=1;i<=m;i++){
		cin>>t[i].a>>t[i].b;
		t[i].len=t[i].a.length();
		for(ll j=0;j<t[i].len;j++)
			if(t[i].a[j]!=t[i].b[j]) {t[i].l=j;break;}
		for(ll j=t[i].len;j>=0;j--)
			if(t[i].a[j]!=t[i].b[j]) {t[i].r=j;break;}
	}
	for(ll i=1;i<=n;i++){
		ll ac=0,bc=0;
		for(ll j=0;j<s[i].len;j++){
			if(s[i].a[j]-'a'>=2||s[i].b[j]-'a'>=2) fb=1;
			if(s[i].a[j]=='a') ac++;else bc++; 
			if(s[i].b[j]=='a') ac++;else bc++; 
		}
		if(bc!=2) fb=1;
	}
	for(ll i=1;i<=m;i++){
		ll ac=0,bc=0;
		for(ll j=0;j<t[i].len;j++){
			if(t[i].a[j]-'a'>=2||t[i].b[j]-'a'>=2) fb=1;
			if(t[i].a[j]=='a') ac++;else bc++; 
			if(t[i].b[j]=='a') ac++;else bc++; 
		}
		if(bc!=2) fb=1;
	}
	
	
	
	if(fb==0){
		for(ll i=1;i<=m;i++){
			for(ll j=1;j<=n;j++){
				ll zxy=0;
				if(t[i].r-t[i].l!=s[j].r-s[j].l) continue;
				if(t[i].l<s[j].l||t[i].len-t[i].r<s[j].len-s[j].r) continue;
				
				
				if(s[j].a[s[j].l]!=t[i].a[t[i].l]) continue;
				if(s[j].b[s[j].l]!=t[i].b[t[i].l]) continue;
				
				if(s[j].a[s[j].r]!=t[i].a[t[i].r]) continue;
				if(s[j].b[s[j].r]!=t[i].b[t[i].r]) continue;
				
				
				z[i]++;
			}
			cout<<z[i]<<"\n";
		}
	}
	else{
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			ll zxy=0;
			if(t[i].r-t[i].l!=s[j].r-s[j].l) continue;
			if(t[i].l<s[j].l||t[i].len-t[i].r<s[j].len-s[j].r) continue;
			
			for(ll w=1;w<=s[j].r-s[j].l+1;w++){
				if(s[j].a[s[j].l+w-1]!=t[i].a[t[i].l+w-1]) break;
				if(s[j].b[s[j].l+w-1]!=t[i].b[t[i].l+w-1]) break;
				if(w==s[j].r-s[j].l+1) zxy=1;
			}
			
			if(zxy==1){
				for(ll w=1;w<=s[j].l;w++){
					if(s[j].a[s[j].l-w]!=t[i].a[t[i].l-w]) break;
					if(s[j].b[s[j].l-w]!=t[i].b[t[i].l-w]) break;
					if(w==s[j].l) zxy=0;
				}
				if(s[j].l==0) zxy=0;
				if(zxy==0){
					for(ll w=1;w<=s[j].len-s[j].r-1;w++){
						if(s[j].a[s[j].r+w]!=t[i].a[t[i].r+w]) break;
						if(s[j].b[s[j].l+w]!=t[i].b[t[i].l+w]) break;
						if(w==s[j].len-s[j].r-1) {
							z[i]++;
						}
					}
					if(s[j].r==s[j].len-1) z[i]++;
				}
				
			}
		}
		cout<<z[i]<<"\n";
	}	
	} 
	
	return 0;
}
