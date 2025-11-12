#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=1,cnt=0,ans=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				f=0;
				cnt++;
				if(a[i-1]==1){
					cnt--;
				}
			}
		}
		if(f)	cout<<n/2<<endl; 
		else	cout<<n-cnt<<endl;
	}
	else if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//0 0 1 1 0
//0 0 0 1 1 1
