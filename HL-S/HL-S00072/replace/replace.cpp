#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005],t1,t2,ts;
long long n,q,num=0,dif,difs[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	memset(difs,0,sizeof(difs));
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]!=s2[i][j]) difs[i]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;num=0;dif=0;
		for(int j=0;j<t1.length();j++){
			if(t1[j]!=t2[j]) dif++;
		}
		for(int j=1;j<=n;j++){//每个s都查一遍
		if(dif<=difs[j]){//s的不同数与t的不同数 
			for(int k=0;k<t1.length();k++){//枚举t的首字母
			if(t1.length()-k>=s1[j].length()){//t后边的长度比s长 
			if(t1[k]==s1[j][0]){//看t的首字母和s的是否一样
				ts=t1; 
				for(int r=0;r<s1[j].length();r++){//将s2变进去 
					if(t1[k+r]==s1[j][r]) ts[k+r]=s2[j][r];//如果每一位都相同 
					else {
						ts="0";
					break;}
				}if(ts==t2) {
				num++;}} 
			}}
		}}cout<<num<<endl; 
	}
	return 0;
}
