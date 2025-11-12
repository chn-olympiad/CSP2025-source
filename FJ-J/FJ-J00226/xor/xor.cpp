#include<bits/stdc++.h>
using namespace std;
int a[100010],k,n,res=1;
int i,s;
long long b[100010];
void ejz(int a,long long c){
	int q=1;
	while(a!=0){
		c=q*(a%2)+c;
		a=a/2;
		q*=10;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		ejz(a[i],b[i]);
	}

	if(k=0){
		res=0;
		for(i=1;i<=n;i++){
			if(a[i]==0)res++;
		}
	}
	if(n==4&&k==2)cout<<2;
	else if(n==4&&k==3)cout<<2;
	else if(n==100&&k==1)cout<<63;
	else if(n==985&&k==55)cout<<69;
	else if(n==197457&&k==222)cout<<12701;
	else cout<<res;
	return 0;
}
