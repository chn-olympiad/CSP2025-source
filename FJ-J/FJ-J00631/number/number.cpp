#include<bits/stdc++.h>
using namespace std;
char num[1000010]={};
int numi=0;
string maxs="",s;
bool cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			//cout<<"CSP-J RP++!!!"<<" ";
			num[numi++]=s[i];
		}
	}
	sort(num,num+numi,cmp);
	for(int i=0;i<numi;i++){
		maxs+=num[i];
	}
	cout<<maxs;
//	for(int i=0;i<numi;i++){
//		cout<<num[i]<<" ";
//	}
	return 0;
}
