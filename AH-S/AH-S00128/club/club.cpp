#include <bits/stdc++.h>
using namespace std;
int a_1[100050],a_2[100050],a_3[100050];
int main (){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	cin>>t;
	while (t--){
		int n;
		cin>>n;
		int flag1=1;
		for (int i=1;i<=n;i++){
			cin>>a_1[i];
			cin>>a_2[i];
			cin>>a_3[i];
			if (a_2[i]!=0 || a_3[i]!=0) flag1=0;
		}
		if (n==2&&!flag1){
			int ans[6]={a_1[1]+a_2[2],a_1[1]+a_3[2],a_2[1]+a_1[2],a_2[1]+a_3[2],a_3[1]+a_1[2],a_3[1]+a_2[2]};
			int num=6;
			int max_1=-1;
			while (num>0){
				if (ans[num-1]>max_1){
					max_1=ans[num-1];
				}
				num--;
			}
			cout<<max_1<<endl;
		}else if(flag1){
			sort(a_1+1,a_1+n+1);
			int sum=0;
			for (int i=n;i>n/2;i--){
				sum+=a_1[i];
			}	
			cout<<sum<<endl;
		}else{
			long long sum1=0;
			for (int i=n;i>n/2;i--){
				sum1+=a_2[i];
			}	
			for (int i=n;i>n/2;i--){
				sum1+=a_1[i];
			}	
			for (int i=n;i>n/2;i--){
				sum1+=a_3[i];
			}	
			cout<<sum1<<endl;
		}
		
	}
	return 0;
}
//这把必得10pts,得不到拉倒
