#include<bits/stdc++.h>
using namespace std;
int a[500010];int b[500010];
long long num=1;
void newn(int n){//n 初始化 
	for(int i=1;i<=25;i++){
 		num*=2;
	}
}

string tent2(long long a){//10转2 
	string s="";
	for(long long i=num;i>=1;i/=2){
		if(a>=i){
			a-=i;
			s=s+'1';
		}else{
			s=s+'0';
		}
	}
	return s;
}

long long twot10(string s){//2转10 
	long long ans=0,tot=1;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='1'){
			ans+=tot;
		}
		tot*=2;
	}
	return ans;
}

long long f(long long a,long long b){//异或 (2)
	string s="";
	string s1=tent2(a),s2=tent2(b);
	for(int i=0;i<s1.size();i++){
		if(s1[i] ==s2[i]) s=s+'0';
		else s=s+'1';
	}
	return twot10(s);
}

long long w(long long l,long long r){//异或和 
	if(l==r) return a[l];
	int t=a[l];
	for(int i=l+1;i<=r;i++){
		t=f(a[l],a[i]);
	}
	return t;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	newn(1);
	int n,k;cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			b[i]=1;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			int t=0;
			for(int z=j-i;z<=j;z++){
				if(b[z]==1)t=1;
			} 
			if(w(j-i,j)==k&&t==0){
				for(int z=j-i;z<=j;z++)b[z]=1;
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
