#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],x,y;
long long i,cnt=0,j;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if((a[i]-a[j]==k||a[i]+a[j]==k)&&a[i]>=0&&a[j]>=0){
				cnt++;
				for(long long z=i;z<=j;z++){
					a[z]=-1;
				}
				break;
			}
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
