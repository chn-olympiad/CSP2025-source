#include<bits/stdc++.h>
using namespace std;
/*
struct nn{
	
}; */
long long a[500005],n,m,q,s,h[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		for(long long j=i;j>q;j--){
			if(h[j]==m){
				break;
			}
			h[j]=h[j]^a[i];
			if(h[j]==m){
				q=j;
				s++;
				break;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 