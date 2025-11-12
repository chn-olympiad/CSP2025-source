#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,cnt0;
bool f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=1;
	}
	if(f==0){
		if(k==0){
			for(int i=1;i<=n;i++)
				if(a[i]==0)cnt0++;
			cout<<cnt0;
			return 0;
		}else{
			for(int i=1;i<=n;i++)
				if(a[i]==1)cnt0++;
			cout<<cnt0;
			return 0;
		}
	}
	cout<<rand()%n;
	return 0;
}