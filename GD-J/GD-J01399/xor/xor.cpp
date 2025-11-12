#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int n,k,ans;
int a[N];
bool b[N]={0};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]==1) continue;
		sum=a[i];
		for(int j=i;j<=n;j++){
			if(sum==k){
				ans++;
				for(int id=i;id<=j;id++)
					b[id]=1;
				break;
			}
			sum=sum^a[j];
		}
		sum=0;
	}
	cout<<ans;
	return 0;
}
