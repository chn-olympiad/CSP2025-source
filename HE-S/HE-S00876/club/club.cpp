#include<bits/stdc++.h>
using namespace std;
struct a{
	long long a1,a2,a3;
}student[10005];		
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long n,x,y,z,sum=0;
		cin>>n;
		long long x1[10005],x2[10005],x3[10005];
		for(int i=1;i<=n;i++){
			cin>>x1[i]>>x2[i]>>x3[i];
			student[i].a1=x1[i];
			student[i].a2=x2[i];
			student[i].a3=x3[i];
		}
		int flag=0,flag1=0;
		for(int i=1;i<=n;i++){
			if(x2[i]!=0 || x3[i]!=0){
				flag=1;
			}
			if(x3[i]!=0){
				flag1=1;
			}
		}
		if(flag==0){
			int cent=n/2;
			sort(x1+1,x1+n);
			for(int i=n;i>n-cent;i--){
				sum+=x1[i];
			}
			cout<<sum<<endl;
		}
	    else if(flag1==0){
			int cent=n/2,maxn=-1,sum1=0;
			
			for(int i=n;i>n-cent;i--){
				for(int i=1;i<=n;i++){
					if(maxn<x1[i]){
						maxn=x1[i];
						sum1=i;
					}
				}
				sum+=maxn;
				a[sum1]=-1;
				maxn=-1;
			}
			
			cout<<sum<<endl;
		}
		else{
			int cent=n/2;
			for(int i=n;i>n-cent;i--){
				sum+=x1[i];
				sum+=x2[i];
				sum+=x3[i];
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
