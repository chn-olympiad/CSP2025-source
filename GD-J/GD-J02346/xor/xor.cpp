#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,cnt=0,pre,a[N],f[N];
int u[N],v[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		u[i]=n-i+1;
	}
	for(int l=1;l<=n;l++){
		pre=1;
		//cout<<l<<endl;
		for(int i=1;i<=n-l+1;i++){
			i=max(i,pre);
			while((u[i]<l&&u[i]>0)||v[i]){
				if(u[i]<l&&u[i]>0){
					i=i+u[i]; 
				} 
				if(v[i]){
					i=i+v[i];
				}				
			}
			if(i>n)break;
			
			f[i]=f[i]^a[i+l-1];
			//cout<<i<<' '<<f[i]<<' '<<u[i]<<' '<<v[i]<<endl;
			u[i+1]=u[i]-1;
			if(u[i]>=l&&f[i]==k){
			//cout<<i<<' '<<l<<endl;
				cnt++;
				u[i+l]=u[i]-l;
				u[pre]=i-pre;
				u[i]=0;
				v[i]=l;
				pre=i+l;
				
			}
		}
	//	u[pre]=n-pre+1;
	}
	cout<<cnt;
	return 0;
} 
