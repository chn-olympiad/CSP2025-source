#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;

int n,m; 
string s[M][3],t[M][3];
int ans[M];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=m;i++){
		cin>>t[i][1]>>t[i][2];
	}
	//通过s把t1变成t2 
	for(int i=1;i<=n;i++){//s
		int len=s[i][1].size();
//		cout<<len<<'*'<<endl;
		for(int j=1;j<=m;j++){//每个t
			for(int k=0;k<t[j][1].size()-len+1;k++){//t的每位 
//				cout<<t[j][1].substr(k,len)<<endl;
//				cout<<k<<' '<<t[j][1].size()-len+1<<'&'<<endl;
				string tt=t[j][1].substr(k,len);
//				cout<<tt<<endl;
				string tt0=t[j][1];
				if(tt==s[i][1]){
					swap(tt,s[i][2]);
					tt0.replace(k,k+len-1,tt);
//					cout<<tt0<<endl;
					if(tt0==t[j][2]){
						ans[j]++;
					}
				}
				
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
	return 0;
} 
