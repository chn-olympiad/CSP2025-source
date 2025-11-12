#include <bits/stdc++.h>
using namespace std;
struct info{
	int a1,a2,a3;
}arr[100000];
int t,n,ans;
bool cmp(info b1,info b2){
	return b1.a1>b2.a1;
}
int main() {
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int ans=0,fs=0;
	for(int i=0;i<t;i++){
		cin>>n;
		int rs=n/2;
		for(int j=0;j<n;j++){
			cin>>arr[j].a1>>arr[j].a2>>arr[j].a3;
			int zh=max(arr[j].a1,max(arr[j].a2,arr[j].a3));
			ans+=zh;
			}
			if(arr[0].a2==0&&arr[0].a3==0){
				sort(arr,arr+n,cmp);
				for(int k=0;k<=rs;k++){
					fs+=arr[k].a1;
				}
				cout<<rs;
				return 0;
		}
			cout<<ans;
	}
	return 0;
} 	
