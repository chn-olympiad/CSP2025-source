#include<bits/stdc++.h>
using namespace std;
long long n,q,c;
string s[int(2e5)][2],t[int(2e5)][2],tmp,tmp1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(long long i=0;i<q;i++){
		cin>>t[i][0]>>t[i][1];
		c=0;
		for(long long j=0;j<n;j++){
			tmp="";
			for(long long k=0;k<int(t[i][0].size()-s[j][0].size());k++){
				for(long long f=k;f<int(s[j][0].size()+k);f++){
					tmp+=t[i][0][f-k];
				}
				if(tmp==s[j][0]){
					tmp1=t[i][0];
					for(long long f=k;f<int(s[j][0].size()+k);f++){
						tmp1[f]=s[j][0][f-k];
					}
					if(tmp1==t[i][1]){
						c++;
					}
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
