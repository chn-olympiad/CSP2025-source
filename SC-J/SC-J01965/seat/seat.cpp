#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,k;
int a[N],c[2];
bool A=1,B=1; 

void funck0(){
	int i,j;
	int tmx=0,mx=0;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(c[0]%2==0 && c[1]%2==0){
				tmx++;
				c[a[j]]++;
				break;
			}
			c[a[j]]++;
		}
		mx=max(mx,tmx);
	}
	cout<<mx;
}

void funck1(){
	int i,j,x;
	int tmx=0,mx=0;
	for(i=1;i<=n;i++){
		for(j=n;j>=i+1;j--){
			c[a[i]]=1;
			for(x=i+1;x<=j;x++){
				if(c[0]==c[1]){
					tmx++;
					c[0]=0;
					c[1]=0;
					c[a[x]]=1;
					continue;
				}
				c[a[x]]++;
			}
			mx=max(mx,tmx);
			tmx=0;
		}
	}
	cout<<mx;
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,j;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]) A=0;
		if(a[i]>1) B=0;
	}
	//A
	if(A) cout<<n/2;
	//B
	else if(B){
		if(!k) funck0();
		else funck1();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 