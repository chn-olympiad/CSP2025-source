#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
string yuan[10001];
string bian[10001];
string jian,kang;
int flag[100001];
int s;
int dfs(int a){
//	cout<<a<<endl;
if(a>=jian.size()&&jian[a]==kang[a])
return 1;
	if(a>=jian.size())
	return 0;
	int f;
	int ans=0;
	if(jian[a]==kang[a]){
		//cout<<a<<endl;
			ans+=dfs(a+1);
	}
	for(int i=0;i<=jian.size()-a-1;i++){
		for(int j=1;j<=s;j++){
			if(flag[j]==0){
			if(yuan[j].size()==i+1){
				f=0;
				for(int k=0;k<yuan[j].size();k++){
					if(yuan[j][k]!=jian[a+k]){
						f=1;
						break;
					} 
				}
				if(f==0){
					for(int k=0;k<bian[j].size();k++){
						if(bian[j][k]!=kang[a+k]){
							f=1;
							break;
						}
					}
					if(f==0){
		
					if(yuan[j].size()==i+1){
					//	cout<<a<<' '<<i<<' '<<j<<' '<<yuan[j]<<' '<<yuan[j].size()<<endl;
						flag[j]=1;
						ans+=dfs(a+i+1);
						flag[j]=0;	
					}
				} 
			}
		}
		}
	}
}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t,a,b,c,d,e,f;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>yuan[i]>>bian[i];
	}
	s=a;
	for(int j=1;j<=b;j++){
		cin>>jian>>kang;
		cout<<dfs(0)<<endl;
	}
	return 0;
} 