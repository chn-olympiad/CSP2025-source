#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
string s[200005][5],temp1,temp2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>s[i][j];
		}
	}
	while(m--){
		ans=0;
		cin>>temp1>>temp2;
		for(int len=1;len<=temp1.size();len++){
			for(int l=0;l+len-1<temp1.size();l++){
				int r=l+len-1;
				string temp3="";
				for(int i=l;i<=r;i++){
					string temp4=" ";
					temp4[0]=temp1[i];
					temp3.append(temp4);
				}
				for(int i=1;i<=n;i++){
					string temp10=temp3;
					if(temp10==s[i][1]){
						temp10=s[i][2];
						string temp5="";
						for(int j=0;j<l;j++){
							string temp6=" ";
							temp6[0]=temp1[j];
							temp5.append(temp6);
						}
						temp5.append(temp10);
						for(int j=r+1;j<temp1.size();j++){
							string temp6=" ";
							temp6[0]=temp1[j];
							temp5.append(temp6);
						}
						if(temp5==temp2) ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

