#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long s4(){
	long long sum=0;
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++){if(a1+a2+a3+a4<3) continue;if(a4!=0&&a1*a[1]+a2*a[2]+a3*a[3]>a[4]) sum++;if(a4==0&&a1*a[1]+a2*a[2]>a3*a[3]) sum++;}
	return sum;
}
long long s5(){
	long long sum=s4();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++){if(a1+a2+a3+a4<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4>a[5]) sum++;}
	return sum;
}
long long s6(){
	long long sum=s5();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++){if(a1+a2+a3+a4+a5<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]>a[6]) sum++;}
	return sum;
}
long long s7(){
	long long sum=s6();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++){if(a1+a2+a3+a4+a5+a6<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]>a[7]) sum++;}
	return sum;
}
long long s8(){
	long long sum=s7();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++) for(int a7=0;a7<=1;a7++){if(a1+a2+a3+a4+a5+a6+a7<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]+a7*a[7]>a[8]) sum++;}
	return sum;
}
long long s9(){
	long long sum=s8();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++) for(int a7=0;a7<=1;a7++) for(int a8=0;a8<=1;a8++){if(a1+a2+a3+a4+a5+a6+a7+a8<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]+a7*a[7]+a8*a[8]>a[9]) sum++;}
	return sum;
}
long long s10(){
	long long sum=s9();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++) for(int a7=0;a7<=1;a7++) for(int a8=0;a8<=1;a8++) for(int a9=0;a9<=1;a9++){if(a1+a2+a3+a4+a5+a6+a7+a8+a9<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]+a7*a[7]+a8*a[8]+a9*a[9]>a[10]) sum++;}
	return sum;
}
long long s11(){
	long long sum=s10();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++) for(int a7=0;a7<=1;a7++) for(int a8=0;a8<=1;a8++) for(int a9=0;a9<=1;a9++) for(int a10=0;a10<=1;a10++){if(a1+a2+a3+a4+a5+a6+a7+a8+a9+a10<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]+a7*a[7]+a8*a[8]+a9*a[9]+a10*a[10]>a[11]) sum++;}
	return sum;
}
long long s12(){
	long long sum=s11();
	for(int a1=0;a1<=1;a1++) for(int a2=0;a2<=1;a2++) for(int a3=0;a3<=1;a3++) for(int a4=0;a4<=1;a4++) for(int a5=0;a5<=1;a5++) for(int a6=0;a6<=1;a6++) for(int a7=0;a7<=1;a7++) for(int a8=0;a8<=1;a8++) for(int a9=0;a9<=1;a9++) for(int a10=0;a10<=1;a10++) for(int a11=0;a11<=1;a11++){if(a1+a2+a3+a4+a5+a6+a7+a8+a9+a10+a11<2) continue;if(a1*a[1]+a2*a[2]+a3*a[3]+a[4]*a4+a5*a[5]+a6*a[6]+a7*a[7]+a8*a[8]+a9*a[9]+a10*a[10]+a11*a[11]>a[12]) sum++;}
	return sum;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=2){
		ans=0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]){
			ans=1;
		}
		else{
			ans=0;
		}
	}
	if(n==4) ans=s4();
	if(n==5) ans=s5();
	if(n==6) ans=s6();
	if(n==7) ans=s7();
	if(n==8) ans=s8();
	if(n==9) ans=s9();
	if(n==10) ans=s10();
	if(n==11) ans=s11();
	if(n==12) ans=s12();
	cout<<ans<<endl;
	return 0;
}
