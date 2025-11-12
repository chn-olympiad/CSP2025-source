#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[6666];
ll ans;
int check4(){
	int ans=0;
	if(a[1]+a[2]+a[3]>2*a[3]) ans++;
	if(a[1]+a[2]+a[4]>2*a[4]) ans++;
	if(a[1]+a[3]+a[4]>2*a[4]) ans++;
	if(a[2]+a[3]+a[4]>2*a[4]) ans++;
	if(a[1]+a[2]+a[3]+a[4]>2*a[4]) ans++;
	return ans;
}
int check5(){
	int ans=0;
	int a1=a[1],a2=a[2],a3=a[3],a4=a[4],a5=a[5];
	if(a1+a2>a3) ans++;
	if(a1+a2>a4) ans++;
	if(a1+a2>a5) ans++;
	if(a1+a3>a4) ans++;
	if(a1+a3>a5) ans++;
	if(a1+a4>a5) ans++;
	if(a2+a3>a4) ans++;
	if(a2+a3>a5) ans++;
	if(a2+a4>a5) ans++;
	if(a3+a4>a5) ans++;
	if(a1+a2+a3>a4) ans++;
	if(a1+a2+a3>a5) ans++;
	if(a1+a2+a4>a5) ans++;
	if(a1+a3+a4>a5) ans++;
	if(a2+a3+a4>a5) ans++;
	if(a1+a2+a3+a4>a5) ans++;
	return ans;
}
int check6(){
	int a1=a[1],a2=a[2],a3=a[3];
	int a4=a[4],a5=a[5],a6=a[6];
	int ans=0;
	if(a1+a2>a3) ans++;
	if(a1+a2>a4) ans++;
	if(a1+a2>a5) ans++;
	if(a1+a2>a6) ans++;
	if(a1+a3>a4) ans++;
	if(a1+a3>a5) ans++;
	if(a1+a3>a6) ans++;
	if(a1+a4>a5) ans++;
	if(a1+a4>a6) ans++;
	if(a1+a5>a6) ans++;
	if(a2+a3>a4) ans++;
	if(a2+a3>a5) ans++;
	if(a2+a3>a6) ans++;
	if(a2+a4>a5) ans++;
	if(a2+a4>a6) ans++;
	if(a2+a5>a6) ans++;
	if(a3+a4>a5) ans++;
	if(a3+a4>a6) ans++;
	if(a3+a5>a6) ans++;
	if(a4+a5>a6) ans++;
	if(a1+a2+a3>a4) ans++;
	if(a1+a2+a3>a5) ans++;
	if(a1+a2+a3>a6) ans++;
	if(a1+a2+a4>a5) ans++;
	if(a1+a2+a4>a6) ans++;
	if(a1+a2+a5>a6) ans++;
	if(a1+a3+a4>a5) ans++;
	if(a1+a3+a4>a6) ans++;
	if(a1+a3+a5>a6) ans++;
	if(a1+a4+a5>a6) ans++;
	if(a2+a3+a4>a5) ans++;
	if(a2+a3+a4>a6) ans++;
	if(a2+a3+a5>a6) ans++;
	if(a2+a4+a5>a6) ans++;
	if(a3+a4+a5>a6) ans++;
	if(a1+a2+a3+a4>a5) ans++;
	if(a1+a2+a3+a4>a6) ans++;
	if(a1+a2+a3+a5>a6) ans++;
	if(a1+a2+a4+a5>a6) ans++;
	if(a1+a3+a4+a5>a6) ans++;
	if(a2+a3+a4+a5>a6) ans++;
	if(a1+a2+a3+a4+a5>a6) ans++;
	return ans;
}
int check7(){
	int ans=0;
	for(int i=1;i<=7;i++){
		for(int j=i+1;j<=7;j++){
			for(int k=j+1;k<=7;k++){
				if(a[i]+a[j]>a[k]) ans++;
			}
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=i+1;j<=7;j++){
			for(int k=j+1;k<=7;k++){
				for(int z=1;z<=k+1;z++){
					if(a[i]+a[j]+a[k]>a[z]) ans++;
				}
			}
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=i+1;j<=7;j++){
			for(int k=j+1;k<=7;k++){
				for(int z=1;z<=k+1;z++){
					for(int l=z+1;l<=7;l++){
						if(a[i]+a[j]+a[k]+a[z]>a[l]) ans++;
					}
				}	
			}
		}
	}
	if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6]||
	   a[1]+a[2]+a[3]+a[4]+a[6]>a[7]||
	   a[1]+a[2]+a[3]+a[5]+a[6]>a[7]||
	   a[1]+a[2]+a[4]+a[5]+a[6]>a[7]||
	   a[1]+a[3]+a[4]+a[5]+a[6]>a[7]||
	   a[2]+a[3]+a[4]+a[5]+a[6]>a[7]||
	   a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[7]) ans++;
	  
	  return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3&&a[1]+a[2]+a[3]>2*a[3]) cout<<1;
	if(n==4&&check4()) cout<<check4();
	if(n==5&&check5()) cout<<check5();
	if(n==6&&check6()) cout<<check6();
	if(n==7&&check7()) cout<<check7();
	return 0;
}
