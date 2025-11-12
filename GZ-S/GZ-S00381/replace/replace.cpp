//GZ-S00381 贵阳市第三中学 胡景涵 
#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,int> qz;
map<string,string> str;

int main(){
	freopen("replace.in","r",stdin); freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s_1,s_2;cin>>s_1>>s_2;
		str[s_1]=s_2;
		for(int j=1;j<=s_1.size();j++){
			qz[s_1.substr(0,j)]++;
			//cout<<s_1.substr(0,j)<<' ';
		}
		//cout<<endl;
	}
	while(q--){
		int ans=0;
		string a,b;cin>>a>>b;
		for(int i=0,j=1;i<a.size();){
			if( qz.count(a.substr(i,j)) && i+j<=a.size()){
				if(str.count(a.substr(i,j)) ){
					string a_=a;
					for(int k=0;k<j;k++){
						a_[k+i]=str[a.substr(i,j)][k];
					}
					if(b==a_) ans++;
				}
				j++;
				
			}
			else{
				i++;j=1;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
