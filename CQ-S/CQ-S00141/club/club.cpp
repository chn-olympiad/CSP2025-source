#include <bits/stdc++.h>
using namespace std;
int n,t;
struct A{
	int a1,a2,a3,cha,m,mz;
}a[100005];
bool mm(A x,A y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long num=0;
		for(int j=1;j<=n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			int l[4];
			l[0]=a[j].a1;
			l[1]=a[j].a2;
			l[2]=a[j].a3;
			sort(l,l+3);
			a[j].m=max(a[j].a1,max(a[j].a2,a[j].a3));
			if(a[j].m==a[j].a1){
				a[j].mz=1;
				
			}
			if(a[j].m==a[j].a2){
				a[j].mz=2;
				
			}
			if(a[j].m==a[j].a3){
				a[j].mz=3;
				
			}
			a[j].cha=a[j].m-l[1];	
		}
		sort(a+1,a+n+1,mm);
		int z[4]={0},ma=n/2;
		for(int j=1;j<=n;j++){
			if(z[a[j].mz]+1<=ma){
				z[a[j].mz]++;
				num+=a[j].m;
			}
			else {
				num+=a[j].m-a[j].cha;
			}
		}
		cout<<num<<endl;
		
	}
	return 0;
} 
