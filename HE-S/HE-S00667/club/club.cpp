#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int ans=0;
		cin>>n;
		int a[100001][4]={},d[100001]={};
		int c=n/2;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			d[i]=a[i][1];
		}
		sort(d,d+n);
		bool flag1=true,flag2=true;
		for(int i=0;i<n;i++){
			if(a[i][2]!=0||a[i][3]!=0){
				flag1=false;
				break;
			}
		}
		
		while(!flag1){	
			for(int i=0;i<n;i++){
				if(a[i][3]!=0){
					flag2=false;
					break;
				}
			}
		}
		if(flag1){
			for(int i=n;i>=c;i--){
				ans+=d[i];
			}
		}else{	
			for(int i=0;i<n;i++){
				int maxn=max(a[i][1],a[i][2]);
				ans+=max(maxn,a[i][3]);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
