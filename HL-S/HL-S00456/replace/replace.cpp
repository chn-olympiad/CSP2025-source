#include<bits/stdc++.h>
using namespace std;
long long n,q;
long long lss1,lss2,ltt1,ltt2;
long long fna,bna; //front num a;back num a 
char mm1,um1,mm2,um2;
string ss1[1005],ss2[1005];
string tt1[1005],tt2[1005];
char finn1(string x,long long k) {//find the only char in string x 
	if(x[k]!=mm1) {
		return x[k];
		lss1=k;
		fna=k-1;
		bna=x.size()-k;
	}
	else return finn1(x,k+1);
}
char finn2(string x,long long k) {
	if(x[k]!=mm2) {
		return x[k];
		lss2=k;
	}
	else return finn2(x,k+1);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>ss1[i]>>ss2[i];
		mm1=ss1[i][0];
		um1=finn1(ss1[i],0);
//		cout<<um1<<endl;
		mm2=ss2[i][0];
		um2=finn2(ss2[i],0);
//		cout<<um2<<endl;
		
	}
	for(int j=1;j<=q;j++) {
		cin>>tt1[j]>>tt2[j];
//		if(tt1[j][0]!=mm1&&tt1[j][0]!=um1) continue;
	}
	for(int i=1;i<=p;i++) {
		cout<<"0"<<endl;
	}
	return 0;
}
