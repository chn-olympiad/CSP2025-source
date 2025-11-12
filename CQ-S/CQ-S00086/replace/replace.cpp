#include<bits/stdc++.h>
using namespace std;

int n,q;
string str1[2003],str2[2003];
string t1[2003],t2[2003];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>str1[i]>>str2[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t1[i]>>t2[i];
		for(int j=0;j<t1[i].size();j++){//每一位开始 
			for(int k=1;k<=n;k++){//对每一个都试试 
				for(int w=0;w<str1[k].size();w++){
					if(w==str1[k].size()-1){//匹配成功 
						int flag=1;
						for(int qwq=str1[k].size();qwq<=n;qwq++){
							if(t1[qwq]!=t2[qwq]){
								flag=0;
								break;
							}
						}
						ans+=flag;
					}
					if(str1[k][w]==t1[i][j]&&str2[k][w]==t2[i][j])continue;
					else break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
