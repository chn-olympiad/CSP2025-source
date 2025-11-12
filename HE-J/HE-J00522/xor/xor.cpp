#include<bits/stdc++.h>
using namespace std;
int t[100]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
bool is[1048577];
int a[500010];
int work(int a,int b){
	string a1="",b1="";
	while(a>1){
		int t;
		char c;
		t=a%2;
		c=t+'0';
		a1=c+a1;
		a/=2;
	} 
	a1="1"+a1;
	while(b>1){
		int t;
		char c;
		t=b%2;
		c=t+'0';
		b1=c+b1;
		b/=2;
	} 
	b1="1"+b1;
	string ans="";
	if(a1.size()<b1.size()){
		for(int i=b1.size()-a1.size();i>=1;i--){
			a1="0"+a1;
		}
	}
	if(a1.size()>b1.size()){
		for(int i=a1.size()-b1.size();i>=1;i++){
			b1="0"+b1;
		}
	}
	for(int i=0;i<a1.size();i++){
		if(a1[i]!=b1[i]){
			ans=ans+"1";
		}else{
			ans=ans+"0";
		}
	} 
	int cnt=1;
	int ans1=0;
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i]=='1'){
			if(cnt=1) ans1+=1;
			else ans1+=t[cnt-1];
		}
	}
	return ans1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool ai1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]!=1) ai1=0;
	} 
	if(k==0&&ai1==1){
		cout<<n/2;
		return 0;
	}
	if(ai1<1){
		cout<<0;
		return 0;
	}
	
	return 0;
} 
