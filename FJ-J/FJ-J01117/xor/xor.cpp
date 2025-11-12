#include<bits/stdc++.h>
using namespace std;
int n;
long long k,cnt;
long long a[500005]; 
bool xb[500005]; 
long long rox(long long a,long long b){
	string x="",y="";
	while(a){
		x+=a%2+'0';
		a/=2;
	}
	while(b){
		y+=b%2+'0';
		b/=2;
	}
	if(x.size()!=y.size()){
		if(x.size()<y.size()){
			for(int i=x.size();i<y.size();i++){
				x+='0';
			}
		}else{
			for(int i=y.size();i<x.size();i++){
				y+='0';
			}
		}
	}
	int len=x.size();
	string ans="";
	for(int i=len-1;i>=0;i--){
		if(x[i]==y[i]) ans+='0';
		else ans+='1';
	}
	long long sum=0;
	for(int i=ans.size()-1;i>=0;i--){
		sum+=(ans[i]-'0')*pow(2,ans.size()-i-1);
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			xb[i]=1;
			cnt++;
			//cout<<1<<endl;
		}
		
	}
	//cout<<n<<k<<endl;
	for(int i=1;i<=n;i++){
		long long ans=a[i];
		if(xb[i]) continue;
		for(int j=i+1;j<=n;j++){
			if(xb[j]) break;
			if(rox(ans,a[j])==k){
				cnt++;
				//cout<<j<<endl;
				i=j+1;
				//cout<<i<<endl;
				//cout<<2<<endl;
			}
			//cout<<ans<<" "<<a[j]<<endl;
		}
	}
	cout<<cnt<<endl;
	return 0;
}//研究半天异或和是啥 
//十年oi一场空，不开longlong见祖宗 
//666要TLE了QwQ
//修一个bug出来另一个bug，关键是有这个bug还不能AC… 
