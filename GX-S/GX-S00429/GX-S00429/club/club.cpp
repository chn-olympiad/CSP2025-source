#include<bits/stdc++.h>
using namespace std;
int a=0;
int b[100005],c[100005],d[100005];
int ans=-1;
void f(int i=0,int p=0,int a1=0,int a2=0,int a3=0){
//	printf("%d %d %d %d %d %d\n",i,p,a1,a2,a3,ans);
	if(i>=a){
		ans=max(ans,p);
		return ;
	}
	if(a1!=a/2)f(i+1,p+b[i],a1+1,a2,a3);
	if(a2!=a/2)f(i+1,p+c[i],a1,a2+1,a3);
	if(a3!=a/2)f(i+1,p+d[i],a1,a2,a3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int qq=0;qq<T;qq++){
		scanf("%d",&a);
		bool A=1;
		for(int i=0;i<a;i++){
			scanf("%d %d %d",&b[i],&c[i],&d[i]);
			if(A==1&&c[i]!=0){
				A=0;
			}
		}if(A==1){
			sort(b,b+a);
			int p=0;
			for(int i=0;i<a/2;i++){
				p+=b[a-i-1];
			}printf("%d\n",p);
		}else {
			f();
			printf("%d\n",ans);
		}ans=-1;
	}
    return 0;
}
