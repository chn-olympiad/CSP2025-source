#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum,v[5000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				if(a[i]==k&&v[j]==0){
					sum++;
					//cout<<i<<" "<<j<<endl;
					v[j]=1;
					i++;
				}
			}else{
				int t=a[i];
				t=int(t^a[j]);
				if(a[j]==k){
					sum++;
					//cout<<j<<" "<<j<<endl;
					v[j]=1;
					i++;
				}
				else if(t==k){
					sum++;
					//cout<<i<<" "<<j<<endl;
					v[j]=1;
					i++;
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
}
