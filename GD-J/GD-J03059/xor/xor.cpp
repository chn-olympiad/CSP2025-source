#include<bits/stdc++.h>
using namespace std;
long long n,l,r,k,sum=-1,num=0,i;
int vis[500001];
unsigned long long a[500001];
void cl(){
	for(int i=l;i<=r;i++){
		vis[i]=1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1,l=1,r=n;i<=r;i++){
		if(sum==-1) sum=a[i];
		else sum^=a[i];
		if(sum==k){
			num++;
			cl();
			l=r;
			sum=-1;
		}
	}
	for(i=1,l=1,r=n;i<=r;i++){
		if(vis[i]){
			sum=-1;
			continue;
		}
		if(sum==-1) sum=a[i];
		else sum&=a[i];
		if(sum==k){
			num++;
			cl();
			l=r;
			sum=-1;
		}
	}
	cout<<num;
	return 0;
} 
