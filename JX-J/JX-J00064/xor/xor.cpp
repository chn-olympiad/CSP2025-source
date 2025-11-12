#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,k,a[N],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0){
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				cnt++;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			s^=a[j];
			if(s==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
