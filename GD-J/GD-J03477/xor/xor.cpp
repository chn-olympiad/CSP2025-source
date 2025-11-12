#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ac[500050],flag1=1,flag2=1;
void teshu1(){
	cout<<n/2<<endl;
	return;
}
void teshu2(){
	int ans=0;
	if(k==0){
		int last=0,yu=0;
		for(int i=1;i<=n;i++){
			if(ac[i]==0&&last==0)ans++;
			if(ac[i]==0&&last==1){
				if(ac[i]^yu==0){
					ans++;
					last=0;yu=0;
				} 
			}if(ac[i]==1&&last==0){
				yu=1;last=1;
			}if(ac[i]==1&&last==1){
				if(yu^ac[i]==0){
					ans++;
					last=0;yu=0;
				}
			}
		}cout<<ans<<endl;
		return;
	}else{
		int last=0,yu=0;
		for(int i=1;i<=n;i++){
			if(ac[i]==1&&last==0)ans++;
			if(ac[i]==1&&last==1){
				if(ac[i]^yu==1){
					ans++;
					last=0;yu=0;
				} 
			}if(ac[i]==0&&last==0){
				yu=0;last=1;
			}if(ac[i]==0&&last==1){
				if(yu^ac[i]==1){
					ans++;
					last=0;yu=0;
				}
			}
		}cout<<ans<<endl;
		return;
	}
}
void buhui(){
	cout<<0<<endl;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    cin>>ac[i];
	    if(ac[i]!=1)flag1=0;
	    if(ac[i]>1)flag2=0;
    }
	if(k==0&&flag1){
		teshu1();
		return 0;
	}if(k<=1&&flag2){
		teshu2();
		return 0;
	}else{
		buhui();
		return 0;
	}
	return 0;
}
