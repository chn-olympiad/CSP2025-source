#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n;
cin>>n;
long long sum=0;
int a1,a2,a3,a4,a5,a6,a7,a[n+1];
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=3;i<=n;i++){
	if(i==3){
		a1=1;
		a2=2;
		a3=3;
		while(1==1){
		int num=0;
		num=num+a[a1]+a[a2]+a[a3];
		int maxx=max(a[a1],max(a[a2],a[a3]));
		if(num>maxx*2) sum++;
		if(a1==n-2&&a2==n-1&&a3==n){
			break;
		}
		if(a1+1<a2) a1++;
		else if(a2+1<a3) a2++;
		else if(a3+1<=n) a3++;
	}	
}
if(i==4){
		a1=1;
		a2=2;
		a3=3;
		a4=4;
		while(1==1){
		int num=0;
		num=num+a[a1]+a[a2]+a[a3]+a[a4];
		int maxx=max(a[a1],max(a[a2],max(a[a3],a[a4])));
		if(num>maxx*2) sum++;
		if(a1==n-3&&a2==n-2&&a3==n-1&&a4==n){
			break;
		}
		if(a1+1<a2) a1++;
		else if(a2+1<a3) a2++;
		else if(a3+1<a4) a3++;
		else if(a4+1<=n) a4++;
	}	
}
if(i==5){
		a1=1;
		a2=2;
		a3=3;
		a4=4;
		a5=5;
		while(1==1){
		int num=0;
		num=num+a[a1]+a[a2]+a[a3]+a[a4]+a[a5];
		int maxx=max(a[a1],max(a[a2],max(a[a3],max(a[a4],a[a5]))));
		if(num>maxx*2) sum++;
		if(a1==n-4&&a2==n-3&&a3==n-2&&a4==n-1&&a5==n){
			break;
		}
		if(a1+1<a2) a1++;
		else if(a2+1<a3) a2++;
		else if(a3+1<a4) a3++;
		else if(a4+1<a5) a4++;
		else if(a5+1<=n) a5++;
	}	
}
if(i==6){
		a1=1;
		a2=2;
		a3=3;
		a4=4;
		a5=5;
		a6=6;
		while(1==1){
		int num=0;
		num=num+a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6];
		int maxx=max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],a[a6])))));
		if(num>maxx*2) sum++;
		if(a1==n-5&&a2==n-4&&a3==n-3&&a4==n-2&&a5==n-1&&a6==n){
			break;
		}
		if(a1+1<a2) a1++;
		else if(a2+1<a3) a2++;
		else if(a3+1<a4) a3++;
		else if(a4+1<a5) a4++;
		else if(a5+1<a6) a5++;
		else if(a6+1<=n) a6++;
	}	
}
if(i==7){
		a1=1;
		a2=2;
		a3=3;
		a4=4;
		a5=5;
		a6=6;
		a7=7;
		while(1==1){
		int num=0;
		num=num+a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7];
		int maxx=max(a[a1],max(a[a2],max(a[a3],max(a[a4],max(a[a5],max(a[a6],a[a7]))))));
		if(num>maxx*2) sum++;
		if(a1==n-6&&a2==n-5&&a3==n-4&&a4==n-3&&a5==n-2&&a6==n-1&&a7==n){
			break;
		}
		if(a1+1<a2) a1++;
		else if(a2+1<a3) a2++;
		else if(a3+1<a4) a3++;
		else if(a4+1<a5) a4++;
		else if(a5+1<a6) a5++;
		else if(a6+1<a7) a6++;
		else if(a7+1<=n) a7++;
	}	
}
}
cout<<sum;
return 0;
}
