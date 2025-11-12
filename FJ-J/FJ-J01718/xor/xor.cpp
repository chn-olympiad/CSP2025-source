#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5e5+5;
const int MAXA=(2<<20)+5;
int n,k;
int a[MAXN];
int spA=0,spB=0,spC=0;
bool s[270];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if (a[i]==1) spA++;
		if (a[i]<=1) spB++;
		if (a[i]<=255)spC++;
	}
	if (k==0 && spA==n) cout<<n/2;
	else if (k<=1 && spB==n){
		int spB_cnt=0;
		if (k==1) cout<<spA;
		else{
			for (int i=1;i<=n;i++){
				if (a[i]==1 && a[i+1]==1){
					spB_cnt++;
					i++;
				}
			}
			cout<<n-spA+spB_cnt;
		}
	}
	
	return 0;
}
//rp++;

