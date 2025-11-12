#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505],p[505];
bool check(){
	int i,j=0,r=0;
	for(i=1;i<=n;i++){
		if(j>=a[p[i]]||s[i]=='0')j++;
		else r++;
		//cout<<j<<' '<<a[p[i]]<<' '<<s[i]<<endl;
	}
	//cout<<r<<' ';
	return r>=m;
}
int main(){
	int i,j=0;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getline(cin,s);
	getline(cin,s);
	s=" "+s;
	for(i=1;i<=n;i++){
		cin>>a[i];
		p[i]=i;
	}
	do{
		if(check()){
			j=(j+1)%998244353;
		}
		//for(i=1;i<=n;i++)cout<<p[i]<<' ';
		//cout<<endl;
	}while(next_permutation(p+1,p+n+1));
	cout<<j;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
