//GZ-S00035 贵阳市观山湖区普瑞学校 全汐阳 
#include <bits/stdc++.h>
using namespace std;

struct node{
	int s1,s2,s3;
	int n1,n2,n3;
	int dp;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	cin>>n;
	for(int i=1;i<=t;i++){
		for(int j=1;i<=n;j++){
			cin>>a[j].s1>>a[j].s2>>a[j].s3;
		}
	}
	for(int i=t;i>=1;i--){
		for(int j=n;i>=1;j--){
			if(a[j].n1<=n/2||a[j].n2<=n/2||a[j].n3<=n/2){
				a[i].dp=a[i].dp+max(a[j].s1,max(a[j].s2,a[j].s3));
				if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s1)
					a[j].n1++;
				else{
					if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s2)
						a[j].n2++;
					else {
						if(max(a[j].s1,max(a[j].s2,a[j].s3))==a[j].s3)
							a[j].n3++;
					}
				}
			}	
			else{
				if(a[j].n1>n/2)
					a[i].dp=a[i].dp+max(a[j].s2,a[j].s3);
				else{
					if(a[j].n2>n/2)
						a[i].dp=a[i].dp+max(a[j].s1,a[j].s3);
					else{
						if(a[j].n3>n/2)
							a[i].dp=a[i].dp+max(a[j].s1,a[j].s2);
					}
				}	
			}
		}
	}	
	for(int i=1;i<=t;i++){
		cout<<a[i].dp<<endl;
	}
	return 0;
}
