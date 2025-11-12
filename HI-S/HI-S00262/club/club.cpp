#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
struct hh{
	int a,b,c,sum;
}b[100005];
bool cmp(hh x,hh y){
	return x.sum>y.sum;
	
}
void yd(){
	int n;
		scanf("%d",&n);
	if(n!=2){
	
	for(int i=1;i<=n;i++){
	
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		b[i].a=a[i][1];
		b[i].b=a[i][2];
		b[i].c=a[i][3];
		b[i].sum=b[i].a+b[i].b+b[i].c;
	}
	long long num1=0,num2=0,num3=0,ans1=0,ans2=0,ans3=0;
	 sort(b+1,b+1+n,cmp);
	 for(int i=1;i<=n;i++){
	 	if(b[i].a>=b[i].b&&b[i].a>=b[i].c){
			if(num1<n/2){
				num1++;
				ans1+=b[i].a;
				b[i].a=0;
				b[i].b=0;
				b[i].c=0;
			}else{
				b[i].a=0;
			}
		}
	 		if(b[i].a<=b[i].b&&b[i].b>=b[i].c){
			if(num2<n/2){
				num2++;
				ans2+=b[i].b;
				b[i].a=0;
				b[i].b=0;
				b[i].c=0;
			}else{
				b[i].b=0;
			}
		}
	if(b[i].c>=b[i].b&&b[i].a<=b[i].c){
			if(num3<n/2){
				num3++;
				ans3+=b[i].c;
				b[i].a=0;
				b[i].b=0;
				b[i].c=0;
			}else{
				b[i].c=0;
			}
		}		
	 }
	 long long ans=ans1+ans2+ans3;
	 printf("%lld\n",ans);
}else{
		for(int i=1;i<=n;i++){
	
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		b[i].a=a[i][1];
		b[i].b=a[i][2];
		b[i].c=a[i][3];
		b[i].sum=b[i].a+b[i].b+b[i].c;
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(i!=j){
			ma=max(ma,a[1][i]+a[2][j]);		
			}
		
		}
	}
	cout<<ma<<endl;
}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		 yd();
	}
	return 0;
}
