#include<iostream>
using namespace std;
typedef long long LL;

LL n,k,ans=0;
LL a[500010];

LL f(LL l,LL r){
	if(l==r){
		return a[l];
	}
	int num=a[l];
	for(int i=l+1;i<=r;i++){
		num^=a[i];
	}return num;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	LL len;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
		len=i;
	}
	
	LL l,r;
	for(l=1;l<=n;l++){
		for(r=l;r<=n;r++){
			if(f(l,r)==k&&l<=r){
				l=r+1;
				r++;
				ans+=1;
			}
		}
	}
	
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
