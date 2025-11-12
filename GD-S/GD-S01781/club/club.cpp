#include<bits/stdc++.h>
using namespace std;
int T;
//int q(int a,int b){
//	if(a<b){
//		int i=a;
//		a=b;
//		b=i;
//	}
//	return a>b;
//}
//int checka(int o){
//	if(o>mxa){
//		
//	}
//}//
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T>0){
	int n;	
//struct{
//	int k;
//	int a1;
//	int b1;
//	int c1;
//}a[100007];
	T--;
	int ans=0;
	cin>>n;
	int a1,b1,c1,an=0,bn=0,cn=0;
	for(int i=1;i<=n;i++){
	cin>>a1>>b1>>c1;
	int f=0;
	if(a1>=b1&&a1>=c1&&f==0){
		if(an<n/2){
			an++;
			ans+=a1;
		}
		else{
			ans+=max(b1,c1);
		}
		f=1;
//		continue;
	}
	if(b1>=c1&&b1>=a1&&f==0){
		if(an<n/2){
			bn++;
			ans+=b1;
		}
		else{
			ans+=max(a1,c1);
		}
//		continue;
	f=1;
	}
	if(c1>=b1&&c1>=a1&&f==0){
		if(cn<n/2){
			cn++;
			ans+=c1;
		}
		else{
			ans+=max(b1,a1);
		}
//		continue;
		f=1;
	}
	}
	printf("%d\n",ans);
//	printf("%d",a[1].a1);
}
return 0;
}
