//GZ-J00398 贵阳中天中学 蒲科印 
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100000],a1,b1,c1,Max[100],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>a[j+1]>>a[j+2];
			sort(a+1;a+j+1);
			Max[j]=a[j+2];
		}
		for(int i=1;i<=n;i++){
			sum+=Max[i];
		}
		cout<<sum<<endl;
	}

	
	return 0;
}
