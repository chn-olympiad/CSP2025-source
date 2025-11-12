#include<bits/stdc++.h>
using namespace std;
int N=5e5+10;
int n,k,x,ans,sum,flag=1;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		if(flag) sum=x,flag=0;
		else sum^=x;
		if(sum==k||x==k) ans++,flag=1;
	}
	cout << ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4

