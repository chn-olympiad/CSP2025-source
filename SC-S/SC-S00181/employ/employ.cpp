#include<iostream>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int ab[10001];
int bb[5];
int cb[31];
string lu;
int yq,rs;
int dfs(int t,int s,int p){
	if(t>rs){
		if(rs-s-p>=yq)
		return 1;
		return 0; 
	}
	 if(s>=ab[t])
	 return dfs(t+1,s,p+1);
	int ans=0;
	 	for(int i=0;i<lu.size();i++){
	 		if(cb[i]==0){
	 			if(lu[i]=='1'){
	 			cb[i]=1;
	 			ans+=dfs(t+1,s,p);
	 	        ans=ans%998244353;
	 	        cb[i]=0;
			 }
			 else{
			 	cb[i]=1;
				ans+=dfs(t+1,s+1,p);//*(bb[1]+1)
	 	        ans=ans%998244353;
	 	        cb[i]=0;
			 }
			 }
		 }
	 return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int a,b,c,d,e,f,g;
    cin>>a>>b>>lu;
    for(int i=1;i<=a;i++){
    	cin>>ab[i];
	}
	rs=a;
	yq=b;
	cout<<dfs(1,0,0);
	return 0;
} 
//*3 2
//101
//1 1 2