#include<bits/stdc++.h>
using namespace std;
vector<int> s;
int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s[i];
	}
	sort(s.begin(),s.end());
	if(t>2){
		int num=0;
		for(int i=1;i<=t;i++){
			for(int j=2;j<=t;j++){
				if(s[i]+s[j]>=s[j+1] && s[i]+s[j]+s[j+1]>s[j+1]*2){
					num+=1;
				}
				else{
					continue;
				}
			}
		}
		for(int k=4;k<t;k++){
			for(int i=1;i<=t;i++){
				int sum=s[i];
				for(int j=1;j<=k;j++){
					sum+=s[i+j];
					if(sum>s[i+k]*2) num+=1;
					else continue;
				}
			}
		}
		cout<<(num+1)%mod<<endl;
	}
	else cout<<"0";
	return 0;
}