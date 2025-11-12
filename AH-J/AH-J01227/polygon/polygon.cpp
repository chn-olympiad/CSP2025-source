#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[200]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1);
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				if(i1+i2>i3){
					ans++;
				}
			}
		}
	}
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				for(int i4=i3+1;i4<=n;i4++){
					if(i1+i2+i3+i4>2*i4){
						ans++;
					}
				}
			}
		}
	}
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				for(int i4=i3+1;i4<=n;i4++){
					for(int i5=i4+1;i5<=n;i5++){
						if(i1+i2+i3+i4+i5>2*i5){
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
