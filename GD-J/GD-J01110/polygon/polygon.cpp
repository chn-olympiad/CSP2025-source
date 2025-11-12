#include<bits/stdc++.h>
using namespace std;
int n,cnt,ma=0,ma2=0,l=0,l2=0,ans=0,bs=0,cs=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j<=n){
				int b[n+5]={0};
				cnt=0;
				l=0;
				bs=0;
				ma=0;
				ma2=0;
				for(int k=i;k<=j;k++){
					cnt+=1; 
					b[cnt]=a[k];
					l=a[k];
					ma=max(ma,a[k]);
				}
				cout<<"#";
				for(int _=1;_<=bs;_++){
					cout<<b[_];
				}
				cout<<" "<<ma<<" "<<l;
				cout<<endl;
				if(bs>=3 && l>ma*2){
					ans+=1;
					cout<<"#";
					for(int _=1;_<=bs;_++){
						cout<<b[_];
					}
					cout<<endl;
				} 
			}
		}
	}
	ans=ans%998%244%353;
	cout<<ans;
	return 0;
}
