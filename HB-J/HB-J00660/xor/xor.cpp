#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],a1[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int f=1;
			int k1=k,ma=0;
			for(int i=1;i<=n;i++){
				a1[i]=a[i];
				ma=max(ma,a[i]);
			}
			while(k1||ma){
				int x=k1%2;
				for(int i1=i;i1<=n;i1++){
					x+=a1[i1]%2;
					a1[i1]/=2;
				}
				ma/=2;
				if(x%2!=0){
					f=0;
					break;
				}
				k1/=2;
			}
			if(f){
				cnt++;
				i=j;
			}
		}
	}
	cout<<cnt;
	return 0;
}
