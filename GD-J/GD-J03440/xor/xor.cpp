#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll k,a[N],ans,sum;
string s,ss,anss;
void to(ll x,ll y){
	s="",ss="";
	while(x){
		if(x&1){
			s+="1";
		}
		else{
			s+="0";
		}
		x>>=1;
	}
	while(y){
		if(y&1){
			ss+="1";
		}
		else{
			ss+="0";
		}
		y>>=1;
	}
	reverse(s.begin(),s.end());
	reverse(ss.begin(),ss.end());
	return ;
}
ll get_ans(string anss){
	int len=anss.size();
	ll cnt=0,k=0;
	for(int i=len-1;i>=0;i--){
		k++;
		if(anss[i]=='1'){
			cnt+=pow(2,k);
		}
	}
	return cnt;
}
ll f(ll x,ll y){
	if(x==0){
		return y;
	}
	if(y==0){
		return x;
	}
	anss="";
	to(x,y);
	int l=s.size(),le=ss.size(),len=max(l,le);
	for(int i=0;i<len;i++){
		int a=s.size(),b=ss.size();
		if(a<b){
			s[i]='0';
		}
		else if(b<a){
			ss[i]='0';
		}
		if(s[i]!=ss[i]){
			anss[i]='1';
		}
		else{
			anss[i]='0';
		}
	}
	return get_ans(anss);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			continue;
		}
		sum=a[i];
		for(int j=i+1;j<=n;j++){
			if(sum==k){
				ans++;
			}
			sum+=f(sum,a[j]);
		}
	}
	printf("%lld",ans);
    return 0;
}
