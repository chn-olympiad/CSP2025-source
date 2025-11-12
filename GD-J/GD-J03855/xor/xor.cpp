#include<bits/stdc++.h>
using namespace std;
int n;
long long a[50005],k;
bool ch[50005];
int ans;
bool x[30],y[30],z[30];
int cp(int a,int b){
	int cans=0,pos1=0,pos2=0;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
		while(a){
		x[pos1++]=a%2;
		a/=2;
	}
	while(b){
		y[pos2++]=b%2;
		b/=2;
	}
	for(int i=0;i<max(pos1,pos2);i++){
		if(x[i]!=y[i]){
			z[i]=1;
		}
		else{
			z[i]=0;
		}
	}
	for(int i=max(pos1,pos2)-1;i>=0;i--){
		cans*=2;
		cans+=z[i];
	}
	return cans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int jans=a[l],pan=1;
			if(ch[l])continue;
			for(int i=l+1;i<=r;i++){
				jans=cp(jans,a[i]);
				if(ch[i])break;
			}
			if((jans==k)&&(pan)){
				ans++;
				for(int i=l;i<=r;i++){
					ch[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
