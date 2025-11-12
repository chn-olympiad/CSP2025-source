#include<bits/stdc++.h>
using namespace std;
int t,n;
int sum=0;
int a[100000],b[100000],c[100000],m;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;int i=0;int one=0,scd=0,trd=0;
	while(t--){
		cin>>n;
		while(n--){
			cin>>a[i]>>b[i]>>c[i];
			m=max(a[i],b[i],c[i]);
			if(m==a[i] and one!=n/2){
				one+=1;
			}else if(m==a[i] and one==n/2){
				continue;
			}else if(m==b[i] and scd!=n/2){
				scd+=1;
			}else if(m==b[i] and scd==n/2){
				continue;
			}else if(m==c[i] and trd!=n/2){
				trd+=1;
			}else if(m==c[i] and trd==n/2){
				continue;
			}i+=1;
		}sort(a+1,a+n+1);
		sort(b+1;b+n+1);
		sort(c+1;c+n+1);
		if((max(a[0],b[0],c[0])+max(a[n],b[n],c[n])+max(a[0],b[0],c[0])%2==1){
			sum+=max(a[0],b[0],c[0])*one+max(a[n],b[n],c[n])*trd;
		}else{
			sum+=max(a[0],b[0],c[0])+max(a[n],b[n],c[n])-1;
		}
		cout<<sum;
	}return 0;
} 

