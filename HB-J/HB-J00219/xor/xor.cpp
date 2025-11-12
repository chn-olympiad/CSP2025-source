#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],ans;
string b,aa[1000005],bb,c;
string yihuo(string a,string b){
	string c;
	for(int i=max(int(a.size()-1),int(b.size()-1));i>=1;i--){
		if(a[i]=='1'&&b[i]!='1'||a[i]!='1'&&b[i]=='1'){
			c+="1";
		}else{
			c+="0";
		}
	}
	string d;
	for(int i=c.size();i>=1;i--){
		d+=c[i];
	}
	return d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(k){
		b+=char(k%2+48);
		k/=2;
	}
	for(int i=b.size()-1;i>=0;i--){
		bb+=b[i];
	}
	for(int i=1;i<=n;i++){
		b="";
		cin>>a[i];
		while(a[i]){
			b+=char(a[i]%2+48);
			a[i]/=2;
		}
		for(int j=b.size()-1;j>=0;j--){
			aa[i]+=b[j];
		}
	}
	for(int i=1;i<=n;i++){
		c=aa[i];
		if(c==bb){
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			if(yihuo(c,aa[j])==bb){
					ans++;
			}else{
				c=yihuo(c,aa[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}
