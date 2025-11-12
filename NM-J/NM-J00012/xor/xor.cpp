#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    bool flag=1,flag0=1;
    int a[500005],cnt1=0,cnt0=0;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=0;
		if(a[i]>1)flag0=0;
		cnt1+=(a[i]==1?1:0);
		cnt0+=(a[i]==0?1:0);
	}
	if(flag)cout<<n/2;
	else if(k==0&&flag0)cout<<cnt0;
	else if(k==1&&flag0)cout<<cnt1;
	else{
		long long sum=0;
		int l[1005][1005];
		for(long long l1=1;l1<=n;l1++){
			for(long long r1=l1;r1<=n;r1++){
				for(long long i=l1;i<=r1;i++){
					l[l1][r1]^=a[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(l[i][j]==k){
					sum++;
					i+=j;
				}
			}
		}
		cout<<sum;
	}
    return 0;
}
/*
 * 约100+100+40+40=280吧
	最低……，不知道……
	燃尽了……
	qwq
	AK,IOI!!
	while(1) rp++;
*/
