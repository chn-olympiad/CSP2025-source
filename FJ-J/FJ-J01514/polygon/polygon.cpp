#include <bits/stdc++.h> std;
using namespace std;
int n,sum;
int a[5010];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){//¸ùÊý 
		for(int j=i;j<=n;j++){
			int b=2;
			int n=1;
			int bo=1;
//			while(bo=1){
//				cout<<1;
			if(a[j-n]+a[j-b]>a[j]){
				sum++;
				b++;
				if(b>j-1){
					b--;
					n++;				
				}
			}else{
				bo=0;
			}				
//			}
		}
	}
	cout<<sum;
	return 0;
}
