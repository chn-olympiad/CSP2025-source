#include<bits/stdc++.h>
using namespace std;

long long n,m,k,r,d=998244353;
map<long long,long long> a,t,l;
string s;
long long c,S=1,q,z;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s="^"+s;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c>0) t[c]++;
	}
	int f=1;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='0'){
			f=0;
			break;
		}
	} if(f==1){
		S=1;
		for(int i=1;i<=n;i++){
			S=S*n%d;
		} cout<<S<<endl;
		return 0;
	}
	
	for(int i=1;i<=n;i++) if(t[i]) l[++r]=i;
	a[n]=t[n];
	for(int i=n-1;i>=0;i--){
		a[i]=a[i+1]+t[i];
	} q=n;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='1') S*=q,q--;
		else{
			z++;
			q=a[z];
			S*=q;
		}
	} cout<<S;
	return 0;
}
