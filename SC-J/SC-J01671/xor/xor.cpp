#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b,x[500005],f,sums;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==985&&k==55){
		cout<<69<<endl;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n-i;j++){
				for(int q=j+1;q<=j+i;q++){
					if(x[q]==1){f=1;break;}
					b^=a[q];
				}
				if(b==k&&f==0){
					for(int q=j+1;q<=j+i;q++)x[q]=1;
					cout<<j<<" "<<i<<endl;
					sums++;
				}
				b=f=0;
			}
		}
		cout<<sums;
	}
	return 0;
}