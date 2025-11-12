#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
int a[100001],b[100001],c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){	
			int s1=a[1]+b[2];
			int s2=a[1]+c[2];
			int s3=b[1]+a[2];
			int s4=b[1]+c[2];
			int s5=c[1]+a[2];
			int s6=c[1]+b[2];
			cout<<max(s1,max(s2,max(s3,max(s4,max(s5,s6)))));
	}else{
			sort(a+1,a+1+n,greater<int>());
			sort(b+1,b+1+n,greater<int>());
			sort(c+1,c+1+n,greater<int>());
			sum=a[1]+b[1]+c[1];
			sum+=max(a[2],max(b[2],c[2]));
			cout<<sum<<endl;
    }
} 
	return 0;
} 
