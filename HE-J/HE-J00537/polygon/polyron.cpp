#include <bits/stdc++.h>
using namespace std;
int a[5010];
long long b;
int main(){
	freopen("polyron.in","r",stdin);
	freopen("polyron.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b+=a[i];
	}
	sort(a+1,a+n+1);
	int s=2;
	int f=0;
	for(int i=1;i<=n*n;i++){
		for(int j=1;j<=n;i++){
			if(j==n){
				if(a[1]*2<b){
					f++;
				}
			}
			while(s+1){
				int c;
				for(int o=1;o<=s+1;o++){
					c=c+a[j];
				}
				if(c*2<b){
					f++;
				}
				c=0;
			}
		}
		s=2*s;
	}
	cout<<f;
	return 0;
} 
