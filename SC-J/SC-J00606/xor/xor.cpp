#include<bits/stdc++.h>
using namespace std;
//^是异或
//这代码能对多少对多少
int n,k,a[500005],go[500005],l,r,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=1;
	for(int i=1;i<=n;i++){
		go[i]=a[i];
		for(int j=l;j<i;j++){
			go[j]=go[j]^a[i];
			
		}
		for(int j=l;j<=i;j++){
			if(go[j]==k){
				l=i+1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}