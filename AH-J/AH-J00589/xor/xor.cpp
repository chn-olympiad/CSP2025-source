#include<bits/stdc++.h>
using namespace std;
int n,k,a[110],maxn,f1;
bool f(int x,int y){
    long long sum=a[x];
	for(int i=x+1;i<=y;i++){
		sum=sum^a[i];
	}
	return sum==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f1=1;
	}
	if(f1==1&&k==0){
        cout<<1;
        return 0;
	}
	int l=1,r=1,mid;
	while(r<=n){
        mid=(l+r)/2;
		if(f(l,r)==1){
            int w=maxn;
            maxn=r-l+1;
            for(int i=l;i<=r;i++){
                if(a[i]==0) maxn--;
            }
            maxn=max(maxn,w);
			r++;
			l++;
		}else{
		    r++;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
