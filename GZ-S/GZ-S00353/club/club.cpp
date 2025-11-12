//GZ-S00353 贵阳市第一中学 程思淇 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout)
	int n=0,t=0,sum2=0,sum3=0,ans = 0;
	int a1[100001]={},a2[100001]={},a3[100001]={};
	cin>>t;
	while(t){
		t--;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]==0) sum2++;
			if(a3[i]==0) sum3++;
		}
		if(sum2==n && sum3==n){
			sort(a1+1,a1+1+n,cmp);
			for(int i=1;i<=n/2;i++) ans+=a1[i];
			sum2 = 0;
			sum3 = 0;
		}
		if(n==2){
			ans = a1[1]+a2[2];
			if(a1[1]+a3[2]>ans) ans = a1[1]+a3[2];
			if(a2[1]+a1[2]>ans) ans = a2[1]+a1[2];
			if(a2[1]+a3[2]>ans) ans = a2[1]+a3[2];
			if(a3[1]+a2[2]>ans) ans = a3[1]+a2[2];
			if(a3[1]+a1[2]>ans) ans = a3[1]+a1[2];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
