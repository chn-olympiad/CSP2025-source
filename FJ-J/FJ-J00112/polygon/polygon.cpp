#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[1]=0;
	b[2]=1;
	b[3]=1;
	int sl;
	while(sl!=n){
		b[1]++;
		sl=0;
		for(int i=1;i<=n;i++){
			if(b[i]==2){
				b[i]=0;
				b[i+1]++;
			}
			if(b[i]==1){
				sl++;
			}
		}
		if(sl>=3){
			int s=0,maxa=-10000;
			for(int i=1;i<=n;i++){
				if(b[i]){
					s+=a[i];
					maxa=max(maxa,a[i]);
				}
			}
			if(s>2*maxa){
				cnt++;
				cnt%=998244353;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
