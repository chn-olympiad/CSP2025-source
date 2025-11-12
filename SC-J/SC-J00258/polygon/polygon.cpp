#include<cstdio>
#include<iostream>
using namespace std;
int n,num,a[5005],ans=0;
void qwe(int kl){
	if(kl==n+1)return;
	int kd=0,op=0;
	for(int i=1;i<=n;i++){
		
		if(kd>2*op)ans++;
		kd=0,op=0;
	}
	qwe(kl++);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int kd=0,op=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			op=max(op,a[i]);
			kd+=a[i];
		}
		if(kd>2*op)printf("1");
		else printf("0");
		return 0;
	}
//	qwe(3);
	printf("%d",ans);
	return 0;
}