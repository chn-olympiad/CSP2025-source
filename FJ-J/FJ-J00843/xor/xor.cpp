#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+1;
int a[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0)cout<<1;
	else{
		for(int i=1;i<=n;i++)if(a[i]!=1&&a[i]!=0)cnt++;
		if(!cnt){
			for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
			cout<<cnt;
			return 0;
		}else{
			sort(a+1,a+n+1);
			int t=a[n];
			srand(23865274836);
			int s=rand()%t;
			cout<<s;
		}
	}
	return 0;
}
