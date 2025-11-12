#include<bits/stdc++.h>
using namespace std;
long long n,q,sum;
string s1,s2,x,y;
map<string,long long>a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdin);
	cin>>n>>q;
	for(long long i=1;i<=n;i++){
		cin>>s1>>s2;
		a[s1]=i;
		b[s2]=i;
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		sum=0;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		for(long long j=0;j<x.size();j++){
			for(long long k=j;k<x.size();k++){
				if(x.substr(0,j)==y.substr(0,j)&&x.substr(k+1,x.size()-k-1)==y.substr(k+1,y.size()-k-1)&&a[x.substr(j,k-j+1)]==b[y.substr(j,k-j+1)]&&a[x.substr(j,k-j+1)]!=0){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
