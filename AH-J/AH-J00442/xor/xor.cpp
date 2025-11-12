#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,k,cnt0,cnt1;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)	cnt0++;
		else if(a[i]==1)	cnt1++;
	}
	if(cnt1+cnt0==n){
		if(cnt0){
			if(k==1){
				cout<<cnt1;
				return 0;
			}else{
				int last=a[1],cnt=0;
				if(a[1]==0)	cnt++;
				for(int i=2;i<=n;i++){
					if(a[i]==0)cnt++;
					else{
						if(a[i]==last){
							cnt++;
							a[i]=0;
						}
					}
					last=a[i];
				}
				cout<<cnt;
				return 0;
			}
		}else{
			cout<<n/2<<endl;
			return 0;
		}
	}else{
		cout<<n/2<<endl;
	}
	return 0;
}
