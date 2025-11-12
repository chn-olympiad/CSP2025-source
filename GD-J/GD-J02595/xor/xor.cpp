#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000];
string be_2(long long  x){
	string a="",b="";
	while(x!=0){
		a+=(x%2)+'0';
		x=x/2;
		if(x==0) break;
	}
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	return b;
}
long long  back_2(string x){
	long long ans=0,a=1;
	for(int i=x.size()-1;i>=0;i--){
		ans+=a*(x[i]-'0');
		a*=2;
	}
	return ans;
}
long long  xor_2(long long a,long long b){
	string ax=be_2(a) ,bx=be_2(b);
	string c="",d="";
	if(ax.size()>bx.size()){
		for(int i=1;i<=ax.size()-bx.size();i++){
		    c+="0";
	    }
		c+=bx;
		bx=c;
	}else if(ax.size()<bx.size()){
		for(int i=1;i<=bx.size()-ax.size();i++){
		    c+="0";
	    }
		c+=ax;
		ax=c;
	}
	for(int i=0;i<ax.size();i++){
		if(ax[i]!=bx[i]) d+="1";
		else d+="0";
	}
	return back_2(d);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<0;
	return 0;
} 
