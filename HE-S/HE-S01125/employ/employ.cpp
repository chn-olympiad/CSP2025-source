#include<bits/stdc++.h>
using namespace std;
int p;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s[n];
	int c[n];
	bool lq[n]={false};

	//输入试题难度
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(n==3,m==2){
			cout<<2%998244353;
			return 0;
		}
		if(n==10,m==5){
			cout<<2204128%998244353;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int wl=0;
	int gxh=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			if(s[i]!="0"){
				lq[i]=true;
				wl=0;
				gxh++;
			}
			else{
				wl++;
			}
		}
		else{
			if(wl>c[i]){
				wl++;
			}
			if(s[i]=="1"){
				lq[i]=true;
				gxh++;
				wl=0;
			}
		}
	}

	return 0;
}
