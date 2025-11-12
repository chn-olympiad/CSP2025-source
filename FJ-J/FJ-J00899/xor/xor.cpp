#include<bits/stdc++.h>
using namespace std;
int n,k,kkk,t=-1,ans,an,l,r;
char kk[25],c[25];
struct a{
	int aaa;
	char aa[25];
	int tt;
};
a a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	t=-1;
	kkk=k;
	do{
		if(kkk%2){
			kk[++t]='1';
		}
		else{
			kk[++t]='0';
		}
		kkk=kkk/2;
	}while(kkk!=0);
	for(int i=1;i<=n;i++){
		cin>>a[i].aaa;
		if(a[i].aaa==1){
			ans++;
		}
		if(a[i].aaa==k){
			an++;
		}
		t=-1;
		do{
			if(a[i].aaa%2){
				a[i].aa[++t]='1';
			}
			else{
				a[i].aa[++t]='0';
			}
		  	a[i].aaa=a[i].aaa/2;
		}while(a[i].aaa!=0);
		a[i].tt=t;
	}
	if(ans==n){
		cout<<n;
		return 0;
	}
	ans=0;
	while(l<=n){
		for(int i=l;i<n;i++){
			for(int j=1;j<25;j++){
				c[j]='0';
			}
			if(i==l){
				if(a[l].aaa==k){
					ans++;
					l++;
				}
			}	
			for(int j=1;j<25;j++){
				if(c[j]!=a[i].aa[j]){
					c[j]='1';
				}
				else{
					c[j]='0';
				}
			}
			an=0;
			for(int j=1;j<25;j++){
				if(c[j]==kk[j]){
					an++;
				}
			}
			if(an==25){
				ans++;
				l=i;
				break;
			}
		}
		l++;	
	}
	cout<<ans;
	return 0;
}