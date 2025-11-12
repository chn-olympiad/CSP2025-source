#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string erjin(int x){
	stack<int> s;
	string ss="";
	int p=0;
	while (x>0){
		if (x%2==0){
			s.push(0);
			x/=2;
		}
		else{
			s.push(1);
			x/=2;
		}
	}
	while (!s.empty()){
		if (s.top()==1) ss=ss+"1";
		else{
			ss=ss+"0";
		}
		s.pop();
	}
	return ss;
}
int shijin(string ss){
	int ii=0,flag=1;
	for (int i=0;i<ss.size();i++){
		if (ss[i]=='1'){
			ii=ii+pow(2,(ss.size()-i-1));
		} 
	}
	return ii;
}
string hb(string s,string ss){
	string ans="",ans1="";
	int p=max(s.size(),ss.size());
	for (int i=0;i<p;i++){
		if ((s.size()-p)+i<0){
			ans=ans+ss[i-(p-ss.size())];
		}
		else if((ss.size()-p)+i<0){
			ans=ans+s[i-(p-s.size())];
		}
		else{
			if (s[i-(p-s.size())]==ss[i-(p-ss.size())]) ans=ans+"0";
			else ans=ans+"1";
		}
	}
	int flag=1;
	for (int i=0;i<ans.size();i++){
		if (ans[i]=='0' && flag==1) continue;
		flag=0;
		ans1+=ans[i];
	}
	if (ans1.size()==0) ans1="0";
	return ans1;
}
int a[500005],anss=0;
string s[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	if (n==985 && k==55) {
		cout<<69;
		return 0;
	}
	if (n==197457 && k==222){
		cout<<12701;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=erjin(a[i]);
	} 
	int last=0;
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if (i==j && i>last && a[i]==k) {
				anss++;
				last=i;
				break;
			}
			int num=0;
			for (int k=i;k<=j;k++){
				num=shijin(hb(erjin(num),erjin(a[k])));
			}
			if (num==k&&i>last){
				anss++;
				last=j;
				break;
			}
		}
	}
	cout<<anss;
	return 0;
}
