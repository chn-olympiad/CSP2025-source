#include<iostream>
using namespace std;
const int N=5e5+5;
int n,k;
int arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int f=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]!=1){
			f=0;
		}
	}
	if(f==1&&k==0){
		cout<<n/2;
		return 0;
	}else if(k<=1){
		int a=0,b=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(arr[i]==1){
				a++;
			}else{
				b++;
			}
			if(a&&b){
				ans++;
				a=0;
				b=0;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
