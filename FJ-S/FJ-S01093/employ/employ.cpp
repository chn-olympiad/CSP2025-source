#include<bits/stdc++.h>
using namespace std;
int n,m,o,shi;
string s;
int h=0;
int a[100001];
long long o1=1;
int b[100001];
int d[1000001];
int dd[100001];
int pd(){
	int f=0;shi=0;
for(int i=1;i<s.size();i++){
	if(s[i]=='1'&&d[i]>shi){
		f++;
	}
	else {
	  	shi++;
	}
}
if(f>=m){
return 1;	
}
return 0;
}
void ee(int t){
	if(t>n){
		
		if(pd()==1){
					for(int i=1;i<=n;i++)cout<<d[i]<<' ';
		cout<<endl;
		o++;
		o%=998244353;
		}
        return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			//cout<<a[i]<<endl;
			d[t]=a[i];
			ee(t+1);
			b[i]=0;
			//d[t]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')h=1;
	}
	if(h==0){
		for(int i=1;i<=n;i++){
			o1*=i;
			o1%=998244353;
		}
		cout<<o1;
		return 0;
	}
	s='0'+s;cout<<s<<endl;
	for(int i=1;i<=n;i++)cin>>a[i];
	ee(1);
	cout<<o;
	return 0;
}
