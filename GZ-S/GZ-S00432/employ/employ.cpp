//GZ-S00432 遵义市第四中学 邓俣宸 
#include<bits/stdc++.h>
using namespace std;
long long n,m,p[1000],o1=1,way1,ss=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			o1=0;
			break;
		}
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
		if(p[i]==0)way1++;
	}if(o1){
		if(n-way1>=m){
			for(int i=1;i<=n;i++){
				ss=ss*i%998244353;
				ss%=998244353;
			}cout<<ss;
		}else{
			cout<<0;
		} 
	}else{
		cout<<0;
	}
	return 0; 
}
