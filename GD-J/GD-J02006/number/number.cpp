#include<bits/stdc++.h>
using namespace std;
string sss;
long long aaa[1000005]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>sss;
	long long ii,jj=0,ll,tt,lenn=sss.size();
	for(ii=0;ii<lenn;ii++){
		if(48<=sss[ii]&&sss[ii]<=57){
			jj++;
			aaa[jj]=(int)sss[ii]-48;
			}
	}
	for(ii=1;ii<=jj;ii++){
		for(ll=jj;ll>ii;ll--){
			if(aaa[ll]>aaa[ll-1]){
				tt=aaa[ll];
				aaa[ll]=aaa[ll-1];
				aaa[ll-1]=tt;
			}
		}
	}
	for(ii=1;ii<=jj;ii++){
		cout<<aaa[ii];
	}
	return 0;
} 

