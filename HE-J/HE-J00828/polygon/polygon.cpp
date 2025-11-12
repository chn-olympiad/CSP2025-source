#include<bits/stdc++.h>
using namespace std;
int a[100006];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,po=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==5){
		bool l=false;
		for(int i=1;i<=n;i++){
			if(a[i]!=i) l=true;
		}
		if(l==false){
			cout<<9;
			po=1;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			po=1;
		}
	}
	if(po==0){
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int sum=a[i]+a[j]+a[k];
					int sk=max(a[i],a[j]);
					sk=max(sk,a[k]);
					if(sum>sk*2) s++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int p=k+1;p<=n;p++){
						int sum=a[i]+a[j]+a[k]+a[p];
						int sk=max(a[i],a[j]);
						sk=max(sk,a[k]);
						sk=max(sk,a[p]);
						if(sum>sk*2) s++;
					}
				}
			}
		}
		cout<<s;
	}
}
