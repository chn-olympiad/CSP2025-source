#include<bits/stdc++.h>
using namespace std;
char c2(string &x){
	int ys=0;
	bool flag=0;
	string x2="";
	for(int i=0;i<x.size();i++){
		int y=x[i]-'0'+ys;
		if(y/2!=0) flag=1;
		if(flag) x2+=y/2+'0';
		ys=y%2*10;
	}
	ys/=10;
	x=x2;
	if(x=="") x="0";
	return ys+'0';
}
void zh(string &x,bitset<20> &ans){
	int cnt=0;
	while(x!="0") ans[cnt++]=c2(x);
}
int n,cnt;
string k;
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<bitset<20> > a; 
	bitset<20> k2(0);
	zh(k,k2);
	for(int i=1;i<=n;i++){
		string s;
		bitset<20> xx;
		cin>>s;
		zh(s,xx);
		a.push_back(xx);
	}
	for(int i=0;i<n;i++){
		bitset<20> x(0);
		for(int j=i;j<n;j++){
			x=x^a[j];
			if(x==k2){
				cnt++;
				i=j;
				break;
			} 
		}
	}
	cout<<cnt;
	return 0;
}
/**/
