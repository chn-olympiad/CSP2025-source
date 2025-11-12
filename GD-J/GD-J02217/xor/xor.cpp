#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int b[100010],ans;
int s=2,l=1,r=1,sum,num;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>b[i];
	while(r-l<n){
		num=b[l];
		for(int i=l+1;i<=r;i++){
			if(b[i]==-1){
				num=-1;
				break;
			}
			num^=b[i];
		}
		if(num==k){
			ans++;
			for(int i=l;i<=r;i++) b[i]=-1;
		}
		l++,r++;
		if(r>n) l=1,r=s,s++;
	}
	cout<<ans;
	return 0;
}
