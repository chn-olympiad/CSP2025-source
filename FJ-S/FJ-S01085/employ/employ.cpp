#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
string s;
int c[505],b[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<s.size();i++){
		b[i]=s[i]-'0';
	}
	for (int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	int x=0,id=-1;
	bool fast=true;
	for (int i=0;i<n;i++){
		if (c[i]==c[i+1] && b[i]==1){
			x++;
			if (fast==true){
				id=i;
			}
			fast=false;
		}else{
			cnt=cnt+x;
			x=0;
			fast=true;
		}
		if (b[i]==1 && c[i]<=i){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

