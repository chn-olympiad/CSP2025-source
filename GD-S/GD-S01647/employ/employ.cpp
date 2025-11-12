#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,t,cnt_yes=0,cnt_no=0;
	cin>>n>>m;
	t=n;
	char a[n]={};
	cin>>a; 
	int c[n+1]={};
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
//	sort(c[1],c[n+1]);
	for(int i=0;i<n-1;i++){
		if(c[i]>c[i+1]){
			int x=c[i];
			c[i]=c[i+1];
			c[i+1]=x;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			cnt_yes++;
		}
		else if(n=='0'||cnt_no>=c[i]){
			cnt_no++;
		}
	}
	cout<<cnt_yes%998244353;
}
