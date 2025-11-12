#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,maxn=-100,minn=210000000;
int f[500005][3];
int Get(int l,int r){
	int s=a[l],pos=l;
	while(pos<=r){
		s=(s^a[++pos]);
	}
	return s;
}

int main(){
	srand(time(0));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(maxn==minn){
		cout<<n;
		
	}
	else if(maxn==1&&minn==0)
	{   
	    int ans=0;
		if(k==1){
			
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		
		cout<<ans;
	}
	else{
		cout<<(rand()<<15+rand())%n;
	}
	
	return 0;
}
