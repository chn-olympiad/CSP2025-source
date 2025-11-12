#include<bits/stdc++.h>
using namespace std;
struct people{
	long long c1,c2,c3;
}a[100010];
bool cmp(people p1,people p2){
	return max(p1.c1,max(p1.c2,p1.c3))>max(p2.c1,max(p2.c2,p2.c3));
}
long long t,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){ 
		cin>>n;
		long long a1[2]={0},a2[2]={0},a3[2]={0},m;
		for(long long i=0;i<n;i++){0
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}sort(a,a+n,cmp);
		for(long long i=0;i<n;i++){
			if(a[i].c1>a[i].c2 && a[i].c1>a[i].c3 && a1[1]<n/2){
				a1[0]+=a[i].c1;a1[1]++;
			}else if(a[i].c2>a[i].c3 && a2[1]<n/2){
				a2[0]+=a[i].c2;a2[1]++;
			}else{
				a3[0]+=a[i].c3;a3[1]++;
			}
		}m=a1[0]+a2[0]+a3[0];
		a1[0]=a2[0]=a3[0]=a1[1]=a2[1]=a3[1]=0;
		for(long long i=n-1;i>=0;i--){
			if(a[i].c1>a[i].c2 && a[i].c1>a[i].c3 && a1[1]<n/2){
				a1[0]+=a[i].c1;a1[1]++;
			}else if(a[i].c2>a[i].c3 && a2[1]<n/2){
				a2[0]+=a[i].c2;a2[1]++;
			}else{
				a3[0]+=a[i].c3;a3[1]++;
			}
		}
		cout<<max(m,a1[0]+a2[0]+a3[0]);
	}
 return 0;
}
