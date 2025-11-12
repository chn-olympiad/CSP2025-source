#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],r[500005],l[500005],m,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int w=1;w<=m;w++){
				if((i>=l[w]&&i<=r[w])||(j>=l[w]&&j<=r[w])||(i>=l[w]&&i<=r[w]&&j>=l[w]&&j<=r[w])){
					flag=false;
					break;
				}
			}
			if(flag){
				long long t=a[i];
				for(int w=i+1;w<=j;w++){
					t=t^a[w];
				}
				if(t==k){
					sum++;
					m++;
					l[m]=i,r[m]=j;
				}
			}else{
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
}
