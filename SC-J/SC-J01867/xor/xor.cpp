#include<bits/stdc++.h>
using namespace std;

int n;
int chh[500005];
int a[500005];
long long ans=0;
int k;
bool flag[500005];

int main(void){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i,j;
	for(i=1;i<=n;i++){
		memset(chh,0,sizeof(chh));
		int c;
		scanf("%d",&c);
		a[i]=c;
		for(j=i;j>=1;j--){
			if(flag[j]||flag[i]){
				break;
			}
			chh[j]=a[j]^chh[j+1];
			if(chh[j]==k){
				ans++;
				flag[i]=1;
				flag[j]=1;
				//cout<<j<<' '<<i<<'\n';
				
			}
		}
		/*
		for(j=1;j<=i+1;j++){
			cout<<chh[j]<<' ';
		}
		cout<<'\n';
		*/
	}
	cout<<ans<<'\n';
	return 0;
}
