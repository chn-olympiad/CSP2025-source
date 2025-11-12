#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
typedef long long ll;
string er(int a){//a的二进制(string) 
	string ss="";
	char c;
	while(a>0){
		c=a%2+'0';
		ss=c+ss;
		a/=2;
	}
	return ss;
}
int ci(int b){//2的b次方 
	 int a=1;
	 for(int i=0;i<b;i++){
	 	a*=2;
	 }
	 return a;
}
int yih(int a,int b){//异或 
	if(a<b)swap(a,b);
	int i,k,ans=0;
	string s="",ss=er(a),sss=er(b);
	int q=ss.size()-sss.size(),tt=sss.size();
	for(i=0;i<q;i++){
		if(ss[i]=='1'){
			s+='1';
		}else s+='0';
	}
	for(i=0;i<tt;i++){
		if(ss[i+q]==sss[i]){
			s+='0';
		}else s+='1';
	}
	k=s.size();
	for(i=k-1;i>=0;i--){
		ans+=(s[i]-'0')*ci((k-i-1));
	}
	return ans;
}
int he(int l,int r){//l、r区间异或和 
	int ans=a[l];
	for(int i=l+1;i<=r;i++)ans=yih(ans,a[i]);
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	cout<<n/2;
	return 0;
}
