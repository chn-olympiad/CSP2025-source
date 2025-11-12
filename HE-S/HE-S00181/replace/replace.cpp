#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=m;i++){
	int ans=1;
		cin>>a>>b;
		if(a.size()>b.size()){
			cout<<0<<endl;
			continue;
		}
		int f=0;
		int flag=0;
		for(int j=0;j<a.size();j++){
			if(a[j]==b[j]){
				f=1;
				flag=0;
			}
			else if(a[j]!=b[j]&&flag==0){
				ans++;
				flag=1;
			}
		}
		if(f==0){
			cout<<0<<endl;
		}
		else{
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
