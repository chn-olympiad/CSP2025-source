#include<bits/stdc++.h>
using namespace std;

int n,kk,a[500010],cnt,bo=1;
bool f[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&kk);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]!=1) {
			bo=0;
		}
		if(a[i]==kk) {
			f[i]=1;
			cnt++;
		}
	}
	if(bo==1) {
		if(kk==1) {
			cout<<n;
		}
		else if(kk==0) {
			cout<<n/2;
		} 
		else {
			cout<<0;
		}
		return 0;
	}
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=n-i;j++) {
			int x=a[j];
			for(int k=j+1;k<=j+i;k++) {
				if(f[k]==1) {
					break;
				}
				x=x^a[k];
			}
			if(x==kk) {
				int r=0;
				for(int k=j;k<=j+i;k++) {
					if(f[k]==1) {
						r=1;
					}
				} 
				if(r==0) {
					cnt++;
				} 
			}
		}
	}
	cout<<cnt;
	
//#Shang4Shan3Ruo6Shui4
	return 0;
}
