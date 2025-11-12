#include<bits/stdc++.h>
using namespace std;
long long ans,x,p,n,m,j,i,k,l,b[5000001],z,t,r,y,a[1000000],v[1000001];
string s;
bool pp(int a,int b){
	return a>b;
}
map<int,map<int ,int> >mp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for (i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)p=1;
	}
	if(p==0){
		for (i=2;i<=n;i++){
			l=1;
			k=0;
			for (j=n;;j--){
				l*=(n-k);
				k++;
				l%=998244353;
				if(k==i)break;
			}
			l/=k;
			ans+=l;
			ans%=998244353;
		}
	}
	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
		cout<<1;
		return 0;
	}
	cout<<0;
} 
