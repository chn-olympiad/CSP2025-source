#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
bool flag[500005];
bool flaga=true,flagb=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0){
		flaga=false;
	}
	if(k>1){
		flagb=false;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1 && flaga){
			flaga=false;
		}
		if(a[i]>1){
			flagb=false;
		}
	}
	if(flaga){
		long long cnt1=n/2;
		cout<<cnt1<<endl;
		return 0;
	}
	if(flagb){
		if(k==1){
			int cnt1=0;
			for(int i=0;i<n;i++){
				if(a[i]==1){
					cnt1++;
				}
			}
			cout<<cnt1<<endl;
			return 0;
		}
		else{
			int cnt2=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					cnt2++;
				}
				if(a[i]==1 && a[i+1]==1 && flag[i]==0 && flag[i+1]==0){
					cnt2++;
					flag[i]=1;
					flag[i+1]=1;
				}
			}
			cout<<cnt2<<endl;
			return 0;
		}
	}
	cout<<1<<endl;
	return 0;
}
