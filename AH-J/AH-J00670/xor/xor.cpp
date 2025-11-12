#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s=-0x3f,cnt,maxx=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1,j=1;i<=n;i++){
		cnt=0;
		while(j<=n){
			s=-0x3f;
			while(s<k){
				if(s==-0x3f) s=a[j];
				else s^=a[j];
				j++;
			}
			if(s==k) cnt++;
		}
		maxx=max(maxx,cnt);
		s^=a[i];
	}
	cout<<maxx;
	return 0;
}
