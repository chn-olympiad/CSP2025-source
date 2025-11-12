#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500011]={},b[500011]={},cnt=1,l[100011],r[100011];
int acnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		b[i]=~(a[i]^b[i-1]);
	}if(a[1]==k)acnt++;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<i;j++){
			if(~(b[j]^b[i])==k){
				acnt++;
				l[acnt]=j+1,r[acnt]=i;
			}
		}
	}cout<<acnt;
	return 0;
}
