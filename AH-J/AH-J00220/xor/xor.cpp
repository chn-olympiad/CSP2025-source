#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans=0,num=0,v[500005],b[500005],flag=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    //a^b;
    for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			ans^=a[j];
			if(ans==k){
				v[i]--;
				v[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+v[i];
		if(b[i]>b[i-1])flag=1;
		else if(b[i]<b[i-1]&&flag==1){
			num++;
			flag=0;
		}
	}
	cout<<num;
    return 0;
   }
