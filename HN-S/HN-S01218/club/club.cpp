#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int h=0;
		int a[100500],b[150000];
		int n=0;
		cin>>n;
		int k;
		for(k=1;k<=n;k++){
			for(int i=1;i<=3;i++){
				cin>>a[i];
			}
			int max=-1;
			for(int i=1;i<=3;i++){
				if(max<a[i]){
					max=a[i];
				}
			}
			b[k]=max;
		}
		for(k=1;k<=n;k++){
			h=h+b[k];
		}
		cout<<h;
	}
	return 0;
}
