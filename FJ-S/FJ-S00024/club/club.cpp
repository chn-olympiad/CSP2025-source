#include<bits/stdc++.h>
using namespace std;
#define long long int
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int arr[n+5][4];
		int brr[n+5];
		int mx1[n+5];
		bool flag1 = true;
		bool flag2 = true;
		for(int i = 1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			mx1[i] = max(arr[i][1],arr[i][2]);
			mx1[i] = max(mx1[i],arr[i][3]);
			brr[i] = arr[i][1];
			if(arr[i][2]!=0){
				flag1 = false;
			}
			if(arr[i][3]!=0){
				flag2 = false;
			}
		}
		int ans = 0;
		if(flag1&&flag2){
			sort(brr+1,brr+1+n);	
			for(int i = n;i>n/2;i--){
				ans+=brr[i];
			}
		}else{
			for(int i = 1;i<=n;i++){
				ans+=mx1[i];
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
