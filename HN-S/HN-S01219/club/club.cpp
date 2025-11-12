#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int N=10002;
int t,n,a[N][4],ans=0;
bool f,g;

void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
}

void slove1(){
	for(int i=1;i<=n;i++){
		if(a[i][1]>=a[i][2]){
			ans+=a[i][1];
		}
		else{
			ans+=a[i][2];
		}
	}
}

void slove2(){
	for(int i=1;i<=n;i++) ans+=a[i][1];
}

void calc(){
	for(int i=1;i<=n;i++){
		if(a[i][3]!=0)f=false;
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i][2]!=0)g=false;
		}
	}
	if(f==true && g==false){
		slove1();
	}
	else if(f==true && g==true){
		slove2();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		f=true;g=true;
		ans=0;
		init();
		calc();
		cout<<ans<<endl;
	}
	return 0;
}
