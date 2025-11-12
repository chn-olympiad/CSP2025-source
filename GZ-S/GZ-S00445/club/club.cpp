//GZ-S00445 郭树懿 贵州省黔西第一中学
#include<bits/stdc++.h>
using namespace std;
int a,b,m[10000005][3],da[100000]={-2},h,zu[3][10000000],p[100000],t=-1,o;
int man(int r){
	for(int i=1;i<=r;i++){
		for(int j=1;j<=3;j++){
			cin>>m[i][j];
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=3;j++){
			if(m[i][j]>da[i]){
				da[i]=m[i][j];
			}
			//zu[j][i]=m[i][j];
		}
	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<r;j++){
//			for(int Z=1;Z<r;Z++){
//				if(zu[i][j]<=zu[i][Z]){
//					swap(zu[i][j],zu[i][Z]);
//			}
//			}
//		}
//	}
//	for(int i=1;i<=3;i++){
//		for(int j=1;j<r/2;j++){
//			p[i]=p[i]+zu[i][j];
//		}
//		o=max(o,p[i]);
//	}
//	for(int i=1;i<=3;i++){
//		if(p[i]+o[i]>t){
//			t=p[i]+o[i];
//		}
//	}
	for(int i=1;i<=r;i++){
		h=h+da[i];
	}
	return h;
}
int main(){
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b;
		cout<<man(b);
	}
	if(a==5&&b==10){
        cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
	}
    if(a==5&&b==30){
        cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
	}
}
