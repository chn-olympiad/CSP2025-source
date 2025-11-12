#include<bits/stdc++.h>
using namespace std;
int c[500],n,m,zs,as;
string a;
long long jg=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a; 
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) zs++;
		if(a[i-1]=='1') as++;
	}if(as<m) cout<<'0';
	else{
		/*sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			cout<<c[i]<<" ";
		}cout<<endl;
		for(int i=1;i<=n;i++){
			if(c[i]>0&&c[i]<=zs){
				zs++;
			}
		}cout<<zs<<endl;*/
		for(int i=2;i<=zs;i++){
			jg*=i;
			jg%=998244353;
		}cout<<jg; jg=1;
	}
	return 0; 
} 
