#include<bits/stdc++.h>
using namespace std;
int t,n,a[3];
int sot(int b,int c,int d){
	if(b==c){
		if(d>c) return 2;
		else return 3;
	}if(c==d){
		if(b>c) return 0;
		else return 4;
	}if(b==d){
		if(c>b) return 1;
		else return 5;
	}if(b>c){
		if(b>d) return 0;
		else return 2;
	}else{
		if(c>d) return 1;
		else return 2;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n; long long x=0,b=0,c=0,d=0;
		for(int i=0;i<n;i++){
			cin>>a[0]>>a[1]>>a[2];
			int f=sot(a[0],a[1],a[2]);
			if(f==0){b++;x+=a[0];}
			if(f==1){c++;x+=a[1];}
			if(f==2){d++;x+=a[2];}
			if(f==3){if(b<c){b++;x+=a[0];}else{c++;x+=a[1];}}
			if(f==4){if(c<d){c++;x+=a[1];}else{d++;x+=a[2];}}
			if(f==5){if(b<d){b++;x+=a[0];}else{d++;x+=a[2];}}
		}if(b<=n/2&&c<=n/2&&d<=n/2) cout<<x<<'\n';
		else cout<<x-1;
	}
	return 0;
}
