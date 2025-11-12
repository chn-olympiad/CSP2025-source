#include<bits/stdc++.h>
using namespace std;
int a[500005],fang[8]={1,2,4,8,16,32,64,128},cnt,n,k,yi,lin;
bool vis[500005];
long long sum=0,b[500005];
bool chec(int c){
	int he=c;
	if((he/k)%2==0){
		return false;
	}
	he=he%k;
	for(int i=7;i>=0;i--){
		if(he>=2*fang[i]){
			he-=2*fang[i];
		}
	}
	if(he!=0){
		return false;
	}else{
		return true;
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				lin++;
			}else if(a[i]==1){
				yi++;
			}
		}
		cout<<lin+yi/2;
		return 0;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				lin++;
			}else if(a[i]==1){
				yi++;
			}
		}
		cout<<yi;
		return 0;
	}else if(k<=255){
		b[0]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k){
				sum++;
			}
			b[i]=b[i-1]+a[i];
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(chec(b[j]-b[i+1])){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	
	return 0;
} 
