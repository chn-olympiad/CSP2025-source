#include<bits/stdc++.h>
using namespace std;
struct edge{
	int l;
	int r;
};
edge c[99999999];
long long n,k,cnt=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n+5];
	for (int i=1;i<=n;i++) cin>>a[i];
	if (k==0){
		int bj=1;
		for (int i=1;i<=n;i++){
			if (a[i]==0){
				bj=0;
			}
			if (a[i]!=1&&a[i]!=0){
				bj=2;
				break;
			}
		}
		if (bj==1){
			cout<<n/2;
			return 0;
		}
		else if (bj==0){
			int js=0;
			for (int i=1;i<n;){
				if (a[i]==a[i+1]){
					js++;
					i+=2;
				}
				else if (a[i]==1&&a[i+1]==0&&a[i+2]==1){
					js++;
					i+=3;
				}
				else i++;
			}
			cout<<js;
			return 0;
		}
	}
	int b[n+5];
	for (int l=1;l<n;l++){
		b[l]=0;
		if (b[l]==k){
			cnt++;
			c[cnt].l=l;
			c[cnt].r=l;
		}
		for (int r=1+1;r<=n;r++){
			b[r]=b[r-1]^a[r];
			if (b[r]==k){
				cnt++;
				c[cnt].l=l;
				c[cnt].r=r;
				break;
			}
		}
	}
	int bjr=c[1].r;
	for (int i=2;i<=cnt;){
		if (bjr>=c[i].l){
			cnt--;
			i++;
		}
		else {
			bjr=c[i].r;
			i++;
		}
	}
	cout<<cnt;
	return 0;
}
