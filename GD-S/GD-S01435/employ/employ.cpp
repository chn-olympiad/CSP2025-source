#include<bits/stdc++.h>
using namespace std;
int a[510];
const int mod=998244353;
int f1(int x){
	long long ans=1;
	for(int i=2;i<=x;i++){
		if(mod/i<ans){
			int num=ans;
			for(int j=2;j<=i;j++){
				if(mod-num<ans){
					int cha=mod-ans;
					ans=num-mod;
					
				}
				else{
					ans+=num;
					
				}
				
			}
	
		}
		else{
			ans*=i;
			
		}
	}
	return ans;
}
int main(){
	freopen("employ.in.txt","r",stdin);
	freopen("employ.out.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	bool isorno=1;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		if(c!='1'){
			isorno=0;
		}
		s+=c;
	}
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	if(isorno){
		cout<<f1(m)<<'\n';
	}
	return 0;
}
