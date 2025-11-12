#include<bits/stdc++.h>
using namespace std;
int n,m,a[509],ju,sum=1,suma=1,ji;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			ju+=1;
			ji++;
		}
		else if(a[i]-ju<0)ju++;
	}
	if(n-ji<m){
		cout<<0;
		return 0;
	}
	int nn=n-ju,mm=n-ji-m;
	sum=nn;
	for(int i=nn-1;i>=1;i--){
		sum=sum*i%998244353;
	}
	suma=nn;
	for(int i=1;i<=mm;i++){
		suma=suma*suma-1%998244353;
	}
	for(int i=1;i<=mm;i++){
		suma=suma/i%998244353;
	}
	if(mm==0)cout<<sum;
	else cout<<sum*mm%998244353;
	return 0;
}
