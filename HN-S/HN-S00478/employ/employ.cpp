#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[520];
char b[520];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=1,l=0,cnx=1;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]=='1'&&l==0){
			cnt++;
		}
		else{
			l=1;
		}
		cnx=cnx*i;
	}
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0&&cnt<m){
		cout<<0;
		return 0;
	}
	if(f==0&&cnt>=m){
		cout<<cnx;
		return 0;	
	}
	cout<<0;
	return 0;
} 

