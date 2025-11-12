#include<bits/stdc++.h>
using namespace std;
long long ln[1001]={0},n,m,zn,ls,h=1;string zdx;
long long jc(int i){
	//if(i<1) return 1;
	if(ln[i]) return ln[i];
	return ln[i]=jc(i-1)*i%998244353;
}
long long a(){
	if(zn<m) return 0;//cout<<endl;
	return jc(zn)/max(h,jc(zn-m));
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ln[1]=1;
	cin>>n>>m;
	cin>>zdx;
	zn=n;
	for(int i=1;i<=n;i++){
		cin>>ls;
		if(!ls) --zn;
	}
	cout<<a();//<<endl<<(62<47)
	//cout<<zn<<endl<<m<<endl;
	fclose(stdin);
	fclose(stdout);
}
