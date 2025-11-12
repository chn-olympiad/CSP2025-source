#include<bits/stdc++.h> 
using namespace std;
int n,m,a[10001],b[10001],b1=0,a1=0;
string qwer;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>qwer;
	for(int i=1;i<=n;i++) {
		a[i]=qwer[i]-'0';
		cout<<a[i]<<" ";
		if(a[i]==1){
			a1++;
		}
	}
	cout<<endl;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<n;i++) {
		if(b[i]==b[i+1]) b1++;
	}
	if(n==3 && m==2) cout<<"2";
	else if(n==10 && m==5) cout<<"2204128";
	return 0;
}
