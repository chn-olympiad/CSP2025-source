#include<bits/stdc++.h>
using namespace std;
string ejz(int a){
	int ans[100001],i=0;
	string an;
	while(a!=1){
		i++;
		ans[i]=a%2;
		a/=2;
	}
	for(int j=1;j<=i;j++){
		an+=ans[j]+'0';
	}
	an+='1';
	return an;
}
int ezs(string a){
	int ans=0;
	for(int i=0;i<a.size();i++){
		ans+=(a[i]-'0')*pow(2,i);
	}
	return ans;
}
int yihuo(int a,int b){
	string x,y,ans;
	int an=0;
	x=ejz(a);
	y=ejz(b);
	for(int i=0;i<min(x.size(),y.size());i++){
		if(x[i]==y[i]) ans[i]='0';
		else ans[i]='1';
	}
	if(x.size()>y.size()){
		for(int i=min(x.size(),y.size());i<max(x.size(),y.size());i++){
			if(x[i]=='1') ans[i]='1';
			else ans[i]='0';
		}
	}
	if(x.size()<y.size()){
		for(int i=min(x.size(),y.size());i<max(x.size(),y.size());i++){
			if(y[i]=='1'){
				ans[i]='1';
			}
			else ans[i]='0';
		}
	}
	an=ezs(ans);
	return an;
}
const int MAXN=5*1e5+1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
cout<<yihuo(2,1);
}
