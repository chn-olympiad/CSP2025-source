#include<bits/stdc++.h>
using namespace std;
int t=0;
struct node{
	int a1,a2,a3;
	bool d=false;
}a[100050],c[100050],b[100050];
bool cmp(node x,node y){
	return x.a1>y.a1;
}
bool cmp1(node x,node y){
	return x.a2>y.a2;
}
bool cmp2(node x,node y){
	return x.a3>y.a3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0,num1=0,num2=0,num3=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;	
			b[i]=a[i],c[i]=a[i];
		}
		sort(a,a+n,cmp);
		sort(b,b+n,cmp1);
		sort(c,c+n,cmp2);
		for(int i=n-1;i>=0;i--){
			if(a[i].d&&b[i].d&&c[i].d){
				continue;
			}
			if(a[i].a1>a[i].a2&&a[i].a1>a[i].a3){
				if(num1++<=n/2){
					num1++;ans+=a[i].a1;a[i].d=true,b[i].d=true,c[i].d=true;
				}
				else if(a[i].a2>a[i].a3&&num2++<=n/2){
					num2++;ans+=b[i].a2;a[i].d=true,b[i].d=true,c[i].d=true;
				}
				else{
					num3++;ans+=c[i].a3;a[i].d=true,b[i].d=true,c[i].d=true;
				}
			}
			else if(a[i].a2>a[i].a1&&a[i].a2>a[i].a3){
				if(num2++<=n/2){
					num2++;ans+=a[i].a2;a[i].d=true,b[i].d=true,c[i].d=true;
				}
				else if(a[i].a1>a[i].a3&&num1++<=n/2){
					num1++;ans+=a[i].a1;a[i].d=true,b[i].d=true,c[i].d=true;
				}
				else{
					num3++;ans+=a[i].a3;a[i].d=true,b[i].d=true,c[i].d=true;
				}
			}
			else{
				num3++;ans+=a[i].a3;a[i].d=true,b[i].d=true,c[i].d=true;
			}
		}
		cout<<ans<<endl;
		for(int i=0;i<n;i++){
			a[i].a1=0,a[i].a2=0,a[i].a3=0,a[i].d=false;
			b[i].a1=0,b[i].a2=0,b[i].a3=0,b[i].d=false;
			c[i].a1=0,c[i].a2=0,c[i].a3=0,c[i].d=false;
		}
		
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int t=0;
struct node{
	int a1,a2,a3;
}a[100050];
int dp[100050][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		int num12=1,num22=1,num32=1,num13=1,num23=1,num33=1,num1=1,num2=1,num3=1;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;	
		}
		dp[0][1]=a[0].a1;
		dp[0][2]=a[0].a2;
		dp[0][3]=a[0].a3;
		for(int i=1;i<n;i++){
			if(num1++<=n/2&&num2++<=n/2&&num3++<=n/2){
				dp[i][1]=max(dp[i-1][1]+a[i].a1,max(dp[i-1][2]+a[i].a1,dp[i-1][3]+a[i].a1));
				if(dp[i][1]>=dp[i][2]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][1]+a[i].a1>dp[i-1][2]+a[i].a1&&dp[i-1][1]+a[i].a1>dp[i-1][3]+a[i].a1)num1++;
					else if(dp[i-1][2]+a[i].a1>dp[i-1][1]+a[i].a1&&dp[i-1][2]+a[i].a1>dp[i-1][3]+a[i].a1)num2++;
					else if(dp[i-1][3]+a[i].a1>dp[i-1][2]+a[i].a1&&dp[i-1][3]+a[i].a1>dp[i-1][1]+a[i].a1)num3++;
				}
			}
			else if(num1++<=n/2&&num2++<=n/2&&num3++>n/2){
				dp[i][1]=max(dp[i-1][1]+a[i].a1,max(dp[i-1][2]+a[i].a1,dp[i-1][3]+a[i].a1));
				if(dp[i][1]>=dp[i][2]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][1]+a[i].a1>dp[i-1][2]+a[i].a1&&dp[i-1][1]+a[i].a1>dp[i-1][3]+a[i].a1)num1++;
					else if(dp[i-1][2]+a[i].a1>dp[i-1][1]+a[i].a1&&dp[i-1][2]+a[i].a1>dp[i-1][3]+a[i].a1)num2++;
				}
			}
			else if(num1++<=n/2&&num2++>n/2&&num3++<=n/2){
				dp[i][1]=max(dp[i-1][1]+a[i].a1,max(dp[i-1][2]+a[i].a1,dp[i-1][3]+a[i].a1));
				if(dp[i][1]>=dp[i][2]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][1]+a[i].a1>dp[i-1][2]+a[i].a1&&dp[i-1][1]+a[i].a1>dp[i-1][3]+a[i].a1)num1++;
					else if(dp[i-1][3]+a[i].a1>dp[i-1][2]+a[i].a1&&dp[i-1][3]+a[i].a1>dp[i-1][1]+a[i].a1)num3++;
				}
			}
			else if(num1++>n/2&&num2++<=n/2&&num3++<=n/2){
				dp[i][1]=max(dp[i][2],dp[i][3]);
			}
			else if(num1++<=n/2&&num2++>n/2&&num3++>n/2){
				dp[i][1]=max(dp[i-1][1]+a[i].a1,max(dp[i-1][2]+a[i].a1,dp[i-1][3]+a[i].a1));
				num1++;
			}
			else if(num1++>n/2&&num2++<=n/2&&num3++>n/2){
				dp[i][1]=dp[i][2];
				num2++;
			}
			else if(num1++>n/2&&num2++>n/2&&num3++<=n/2){
				dp[i][1]=dp[i][3];
				num3++;
			}
			
			
			if(num12++<=n/2&&num22++<=n/2&&num32++<=n/2){
				dp[i][2]=max(dp[i-1][1]+a[i].a2,max(dp[i-1][2]+a[i].a2,dp[i-1][3]+a[i].a2));
				if(dp[i][2]>=dp[i][1]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][1]+a[i].a2>dp[i-1][2]+a[i].a2&&dp[i-1][2]+a[i].a2>dp[i-1][3]+a[i].a2)num12++;
					else if(dp[i-1][2]+a[i].a2>dp[i-1][1]+a[i].a2&&dp[i-1][2]+a[i].a2>dp[i-1][3]+a[i].a2)num22++;
					else if(dp[i-1][3]+a[i].a2>dp[i-1][2]+a[i].a2&&dp[i-1][3]+a[i].a2>dp[i-1][1]+a[i].a2)num32++;
				}
			}
			else if(num12++<=n/2&&num22++<=n/2&&num32++>n/2){
				dp[i][2]=max(dp[i-1][1]+a[i].a2,max(dp[i-1][2]+a[i].a2,dp[i-1][3]+a[i].a2));
				if(dp[i][2]>=dp[i][1]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][1]+a[i].a2>dp[i-1][2]+a[i].a2&&dp[i-1][2]+a[i].a2>dp[i-1][3]+a[i].a2)num12++;
					else if(dp[i-1][2]+a[i].a2>dp[i-1][1]+a[i].a2&&dp[i-1][2]+a[i].a2>dp[i-1][3]+a[i].a2)num22++;
				}
			}
			else if(num12++<=n/2&&num22++>n/2&&num32++<=n/2){
				dp[i][3]=max(dp[i-1][1]+a[i].a3,max(dp[i-1][2]+a[i].a3,dp[i-1][3]+a[i].a3));
			}
			else if(num12++>n/2&&num22++<=n/2&&num32++<=n/2){
				dp[i][2]=max(dp[i-1][2]+a[i].a2,max(dp[i-1][2]+a[i].a2,dp[i-1][3]+a[i].a2));
				if(dp[i][2]>=dp[i][1]&&dp[i][1]>=dp[i][3]){
					if(dp[i-1][2]+a[i].a2>dp[i-1][1]+a[i].a2&&dp[i-1][2]+a[i].a2>dp[i-1][3]+a[i].a2)num22++;
					else if(dp[i-1][3]+a[i].a2>dp[i-1][2]+a[i].a2&&dp[i-1][3]+a[i].a2>dp[i-1][1]+a[i].a2)num32++;
				}
			}
			else if(num12++<=n/2&&num22++>n/2&&num32++>n/2){
				dp[i][2]=dp[i][1];
				num12++;
			}
			else if(num12++>n/2&&num22++<=n/2&&num32++>n/2){
				dp[i][2]=max(dp[i-1][1]+a[i].a2,max(dp[i-1][2]+a[i].a2,dp[i-1][3]+a[i].a2));
				num22++;
			}
			else if(num12++>n/2&&num22++>n/2&&num32++<=n/2){
				dp[i][2]=dp[i][3];
				num32++;
			}
			
			
			
			if(num13++<=n/2&&num23++<=n/2&&num33++<=n/2){
				dp[i][3]=max(dp[i-1][1]+a[i].a3,max(dp[i-1][2]+a[i].a3,dp[i-1][3]+a[i].a3));
				if(dp[i][3]>=dp[i][1]&&dp[i][3]>=dp[i][2]){
					if(dp[i-1][1]+a[i].a3>dp[i-1][2]+a[i].a3&&dp[i-1][2]+a[i].a3>dp[i-1][3]+a[i].a3)num13++;
					else if(dp[i-1][2]+a[i].a3>dp[i-1][1]+a[i].a3&&dp[i-1][2]+a[i].a3>dp[i-1][3]+a[i].a3)num23++;
					else if(dp[i-1][3]+a[i].a3>dp[i-1][2]+a[i].a3&&dp[i-1][3]+a[i].a3>dp[i-1][1]+a[i].a3)num33++;
				}
			}
			else if(num13++<=n/2&&num23++<=n/2&&num33++>n/2){
				dp[i][3]=max(dp[i][1],dp[i][2]);
			}
			else if(num13++<=n/2&&num23++>n/2&&num33++<=n/2){
				dp[i][2]=max(dp[i][1],dp[i][3]);
				if(dp[i][3]>=dp[i][2]&&dp[i][3]>=dp[i][1]){
					if(dp[i-1][1]+a[i].a3>dp[i-1][2]+a[i].a3&&dp[i-1][2]+a[i].a3>dp[i-1][3]+a[i].a3)num13++;
					else if(dp[i-1][3]+a[i].a3>dp[i-1][2]+a[i].a3&&dp[i-1][3]+a[i].a3>dp[i-1][1]+a[i].a3)num33++;
				}
			}
			else if(num13++>n/2&&num23++<=n/2&&num33++<=n/2){
				dp[i][3]=max(dp[i-1][2]+a[i].a3,max(dp[i-1][2]+a[i].a3,dp[i-1][3]+a[i].a3));
				if(dp[i][3]>=dp[i][2]&&dp[i][3]>=dp[i][1]){
					if(dp[i-1][2]+a[i].a3>dp[i-1][1]+a[i].a3&&dp[i-1][2]+a[i].a3>dp[i-1][3]+a[i].a3)num23++;
					else if(dp[i-1][3]+a[i].a3>dp[i-1][2]+a[i].a3&&dp[i-1][3]+a[i].a3>dp[i-1][1]+a[i].a3)num33++;
				}
			}
			else if(num13++<=n/2&&num23++>n/2&&num33++>n/2){
				dp[i][3]=dp[i][1];
				num13++;
			}
			else if(num13++>n/2&&num23++<=n/2&&num33++>n/2){
				dp[i][3]=dp[i][2];
				num23++;
			}
			else if(num13++>n/2&&num23++>n/2&&num33++<=n/2){
				dp[i][3]=max(dp[i-1][1]+a[i].a3,max(dp[i-1][2]+a[i].a3,dp[i-1][3]+a[i].a3));
				num33++;
			}
		}
		if(num1<=n/2&&num2<=n/2&&num3<=n/2&&num12<=n/2&&num22<=n/2&&num32<=n/2&&num13<=n/2&&num23<=n/2&&num33<=n/2)
			cout<<max(dp[n-1][1],max(dp[n-1][2],dp[n-1][3]))<<endl;
		else if(num12<=n/2&&num22<=n/2&&num32<=n/2&&num13<=n/2&&num23<=n/2&&num33<=n/2)
			cout<<max(dp[n-1][2],dp[n-1][3])<<endl;
		else if(num1<=n/2&&num2<=n/2&&num3<=n/2&&num13<=n/2&&num23<=n/2&&num33<=n/2)
			cout<<max(dp[n-1][1],dp[n-1][3])<<endl;
		else if(num1<=n/2&&num2<=n/2&&num3<=n/2&&num12<=n/2&&num22<=n/2&&num32<=n/2)
			cout<<max(dp[n-1][1],dp[n-1][2])<<endl;
		else if(num1<=n/2&&num2<=n/2&&num3<=n/2)
			cout<<dp[n-1][1]<<endl;
		else if(num12<=n/2&&num22<=n/2&&num32<=n/2)
			cout<<dp[n-1][2]<<endl;
		else if(num13<=n/2&&num23<=n/2&&num33<=n/2)
			cout<<dp[n-1][3]<<endl;
		num12=1,num22=1,num32=1,num13=1,num23=1,num33=1,num1=1,num2=1,num3=1;
		for(int i=0;i<n;i++){
			a[i].a1=0,a[i].a2=0,a[i].a3=0;
			dp[i][1]=0;dp[i][2]=0;dp[i][3]=0;
		}
	}
	return 0;
}
*/
