#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[500010];
string add(string a,string b){
	int la=a.size(),lb=b.size();
	int l=max(la,lb);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	if(la<l){
		for(int i=la;i<l;i++)a+='0';
	}
	if(lb<l){
		for(int i=lb;i<l;i++)b+='0';
	}
	string w="";
	for(int i=0;i<l;i++){
		if(a[i]!=b[i])w+='1';
		else w+='0';
	}
	reverse(w.begin(),w.end());
	int j=0;
	while(w[j]=='0'&&j!=l-1)j++;
	string ans="";
	for(int i=j;i<l;i++)ans+=w[i];
	return ans;
}
string a_2(int n){
	string w="";
	while(n){
		w+=n%2+'0';
		n/=2;
	}
	reverse(w.begin(),w.end());
	return w;
}
long long a_10(string w){
	long long sum=0;
	int l=w.size();
	for(int i=l-1;i>=0;i--){
		if(w[i]=='1'){
			long long k=1;
			for(int j=1;j<l-i;j++){
				k*=2;
			}
			sum+=k;
	}
}
	return sum;
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
int r=1,ans=0;
string s=a_2(a[1]);
for(int i=1;i<=n;i++){
	long long x;
	string p=a_2(a[i]);
	if(i==r)x=a_10(p);
	else x=a_10(add(s,p));
	if(x==k){
		r=i+1;
		ans++;
		s=a_2(a[r]);
	}
	else if(x>k){
		r++;i=r-1;
	}
	else{
		if(i>r)s=add(s,p);
		else s=a_2(a[r]);
	}
}
cout<<ans;
return 0;
}
