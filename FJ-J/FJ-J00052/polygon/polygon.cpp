#include<bits/stdc++.h>
using namespace std;
long long a[5005],b[5005],num,n;
void k(long long z,long long m,int w,int s){
	for(int i=s;i<=n;i++){
		if(w==0&&i>=n-1)break;
		if(b[i]==0){
			b[i]=1;
			k(z+a[i],max(m,a[i]),w+1,s+1);
			b[i]=0;
		}
	}
	if(s>=3&&z>2*m)num++;
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	k(0,0,0,1);
	cout<<num%998%244%353;
	return 0;
} 
