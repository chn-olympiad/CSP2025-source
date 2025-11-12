#include <bits/stdc++.h>
const int N=5e5+10;
using namespace std;
long long n,k,a[N],b[N],ans;
string t[N],last;
int check(string x,string y){
	long long p=0,s=0;
	if(x.size()>y.size()) swap(x,y);
	for(int i=1;i<=y.size()-x.size();i++){
		x='0'+x;
	}
	for(int i=x.size()-1;i>=0;i--){
		if(x[i]!=y[i]) s+=pow(2,p);
		p++; 
	}
	return s;
}
string er(int l){
	string w="";
	if(l==0){
		w="0";
		return w; 
	}
	while(l!=0){
		w+=char((l%2)+'0');
		l/=2;
	}
	return w;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long now=a[i];
		if(now==0){
			t[i]="0";
			continue;
		}
		while(now!=0){
			t[i]+=char((now%2)+'0');
			now/=2;
		}
	}
	for(int i=1;i<=n;i++){
		string x="";
		for(int j=t[i].size()-1;j>=0;j--){
			x+=t[i][j];
		}
		t[i]=x;
	}
	last=t[1];
	if(a[1]==k){
		ans++;
		last="0";
	}
	for(int i=2;i<=n;i++){
		long long l=check(last,t[i]);
		if(l==k){
			ans++;
			last="0"; 
		}else{
			last=er(l);
		}
	}
	printf("%lld",ans);
	return 0; 
}
