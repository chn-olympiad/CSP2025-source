#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
int read(){
	int x=0,f=1;
	char ac=getchar();
	while(ac<'0'||ac>'9'){
		if(ac=='-') f=-1;
		ac=getchar();
	}
	while(ac>='0'&&ac<='9'){
		x=(x<<3)+(x<<1)+(ac-'0');
		ac=getchar();
	}
	return x*f;
}
int t,n,a[100005][3],top1,top2,top3,sta1[100005],sta2[100005],sta3[100005],ans;
void work(){
	top1=top2=top3=0;
	ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
	} 
	for(int i=1;i<=n;i++){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			ans+=a[i][0];
			sta1[++top1]=a[i][0]-std::max(a[i][1],a[i][2]);
		}
		else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
			ans+=a[i][1];
			sta2[++top2]=a[i][1]-std::max(a[i][0],a[i][2]);
		}
		else{
			ans+=a[i][2];
			sta3[++top3]=a[i][2]-std::max(a[i][0],a[i][1]);
		}
	}
	int m=n/2;
	if(top1>m){
		std::sort(sta1+1,sta1+top1+1);
		for(int i=1;i<=top1-m;i++) ans-=sta1[i];
	}
	else if(top2>m){
		std::sort(sta2+1,sta2+top2+1);
		for(int i=1;i<=top2-m;i++) ans-=sta2[i];
	}
	else if(top3>m){
		std::sort(sta3+1,sta3+top3+1);
		for(int i=1;i<=top3-m;i++) ans-=sta3[i];
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) work();
	return 0;
}
