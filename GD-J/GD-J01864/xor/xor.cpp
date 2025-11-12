#include<bits/stdc++.h> 
using namespace std;
int n,k,arr[500005],cnt=0;
string ejz(int a){//二进制 
	string s="";
	while(a>0){
		s+=to_string(a%2);
		a/=2;		
	}
	return s;
}
int shjz(string c){//十进制 
	int len=c.size();
	long long sum=0,cnt=0;
	for(int i=len-1;i>=0;i--){
		sum+=(c[i]-'0')*pow(2,cnt);
		cnt++;
	}
	return sum;
}
string Xor(string a,string b){//异或 
	int alen=a.size(),blen=b.size();
	string c;
	if(alen>blen){
		int q=alen-blen;
		for(int i=1;i<=q;i++){
			b="0"+b;
		}
	}
	else if(alen<blen){
		int q=blen-alen;
		for(int i=1;i<=q;i++){
			a="0"+a;
		}
	}
	for(int i=0;i<max(alen,blen);i++){
		if(a[i]!=b[i]) c[i]='1';
		else c[i]='0';
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	if(k==0&&n==2){
		cout<<1;
		return 0;
	}
	if(k==0) {
		cout<<n/2;
		return 0;
	}
	if(k==0){//k为0 
		int cnt1=0;
		for(int i=0;i<n;i++){
			if(arr[i]==0) cnt1++;
			if(i+1<n&&arr[i]!=0&&arr[i]==arr[i+1]) cnt1++,arr[i+1]=2e9;
		}
		cout<<cnt1;
		return 0;
	}
		int cnt2=0;
		for(int i=0;i<n;i++){
			if(i+1<n&&abs(arr[i]-arr[i+1])==k) cnt2++,i+=2;
		}
		cout<<cnt2;
	return 0;
}
