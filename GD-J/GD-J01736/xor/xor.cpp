#include<bits/stdc++.h>
using namespace std;
#define ll long long
	int n,k,a[500005],fa=1,fb=1,fc=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)fa=0;
		if(a[i]>1)fb=0;
		if(a[i]>255)fc=0;
	}
	if(fa){
		cout<<n/2;
		return 0;
	}
	if(fb){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++)cnt+=a[i];
			cout<<cnt;return 0;
		}
		else{
			int cnt=0,cc=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
					cnt+=cc/2;
					cc=0;
				}
				else cc++;
			}
			cout<<cnt;
			return 0;
		}
	}
	
	
	return 0; 
}
