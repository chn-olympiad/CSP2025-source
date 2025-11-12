#include<bits/stdc++.h>
using namespace std;
struct node{
	int n,p;
}a[501];
int ton[501];
char s[501];
bool cmp(node &a,node &b){
	return a.p>b.p;
}
long long fun(int t){
	if(t==1){
		return 1;
	}
	return t*fun(t-1)%998244353;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i].p;
		a[i].n=i;
	}
	int zt=0;
	for(int i=1;i<=n;i++){
		if(ton[i]==0){
			ton[i]=ton[i-1];
		}
		if(s[i]=='0'){
			zt++;
			if(s[i+1]=='1'){
				ton[i+1]=zt;
			}
		}
		if(i>=m&&zt==0){
			cout<<fun(n);
			return 0;
		}
	}
	sort(a+1,a+n+1,cmp);
	cout<<fun(n);
	return 0;
}
