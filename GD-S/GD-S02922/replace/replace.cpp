#include "bits/stdc++.h"
using namespace std;
string qz[200005],hz[200005],real1[200005],real2[200005];
int main(void){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string tmp1,tmp2;
		cin>>tmp1>>tmp2;
		int i1,i2;
		for(i1=0;i1<(int)tmp1.length() && tmp1[i1]==tmp2[i1];i1++);
		for(i2=(int)tmp1.length();i2>0 && tmp1[i2]==tmp2[i2];i2--);
		for(int j=0;j<i1;j++) qz[i]+=tmp1[j];
		for(int j=i2+1;j<(int)tmp1.length();j++) hz[i]+=tmp1[j];
		for(int j=i1;j<=i2;j++) real1[i]+=tmp1[j],real2[i]+=tmp2[j];
	}
	for(int i=1;i<=q;i++){
		string tmp1,tmp2,_real1="",_real2="",_qz="",_hz="";
		cin>>tmp1>>tmp2;
		int i1,i2;
		for(i1=0;i1<(int)tmp1.length() && tmp1[i1]==tmp2[i1];i1++);
		for(i2=(int)tmp1.length();i2>0 && tmp1[i2]==tmp2[i2];i2--);
		for(int j=0;j<i1;j++) _qz+=tmp1[j];
		for(int j=i2+1;j<(int)tmp1.length();j++) _hz+=tmp1[j];
		for(int j=i1;j<=i2;j++) _real1+=tmp1[j],_real2+=tmp2[j];
		int ans=0;
		for(int j=1;j<=n;j++)
			if(_qz.find(qz[j])!=-1 && _hz.find(hz[j])!=-1 && _real1==real1[j] && _real2==real2[j])
				ans++; 
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
}
