#include<bits/stdc++.h>
using namespace std;
int n,m,f[110000],ans;
string s[110000],k="";
string er(int a){
	string x,y;
	while(a!=0){
		x+=(a%2)+'0';
		a/=2;
	}
	for(int i=x.size()-1;i>=0;i--){
		y+=x[i];
	}
	return y;
}
string xo(string a,string b){
	int le=min(a.size(),b.size());
	string c="";
	for(int i=0;i<le;i++){
		if(a[a.size()-i-1]!=b[b.size()-i-1]) c=c+'1';
		else c=c+'0';
	}
	if(a.size()>b.size()){
		for(int i=0;i<a.size()-le;i++){
			c=a[i]+c;
			/*if(a[i]==0) c+='1';
			else c+='0';*/
		}
	}
	else if(a.size()<b.size()){
		for(int i=0;i<b.size()-le;i++){
			c=b[i]+c;
			/*if(b[i]==0) c+='1';
			else c+='0';*/
		}
	}
	return c;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	//cout<<xo("10","1")<<' '<<xo(xo("10","1"),"0");
	k=er(m);
	for(int i=1;i<=n;i++){
		cin>>m;
		s[i]=er(m);
		if(k==s[i]){
			f[i]=1;
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]!=1){
			string su=s[i];
			int mi=1e9;
			if(f[i]!=0) mi=f[i];
			for(int j=i+1;j<=n;j++){
				mi=min(mi,f[j]);
				if(j-i>=mi and mi!=0) break;
				su=xo(su,s[j]);
				if(su==k){
					for(int w=j;w<=n;w++){
						if(f[w]==1) break;
						else f[w]=0;
					}
					if(mi==0){
						ans++;
						break;
						//cout<<'-'<<i<<'-';
					}
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
