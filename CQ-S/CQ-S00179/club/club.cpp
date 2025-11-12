#include <bits/stdc++.h>
using namespace std;
int n,t,sum;
struct id{
	int q1,q2,q3;
	bool lo;
}a[500001];
bool o1(id x,id y){
	/*if(x.q1==y.q1){
		if(x.q2==y.q2){
			return x.q3>y.q3;
		}return x.q2>y.q2;
	}*/return x.q1>y.q1;
}bool o2(id x,id y){
	/*if(x.q2==y.q2){
		if(x.q3==y.q3){
			return x.q1>y.q1;
		}return x.q3>y.q3;
	}*/return x.q2>y.q2;
}bool o3(id x,id y){
	/*if(x.q3==y.q3){
		if(x.q1==y.q1){
			return x.q2>y.q2;
		}return x.q1>y.q1;
	}*/return x.q3>y.q3;
}
//for(int i=1;i<=n;i++){}
//if(){}
//int op(){}
//void op(){}
//scanf("%",&);printf("%",);
//[1000]
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j].q1,&a[j].q2,&a[j].q3);
		}sort(a+1,a+n+1,o1);
		int ow=0;
		for(int j=1;j<=n&&ow<n/2;j++){
			if(a[j].lo==0&&a[j].q1>a[j].q2&&a[j].q1>a[j].q3){
				a[j].lo=1; 
				//printf("1 %d\n",a[j].q1);
				sum+=a[j].q1;
				ow++;
			}
		}sort(a+1,a+n+1,o2);
		ow=0;
		for(int j=1;j<=n&&ow<n/2;j++){
			if(a[j].lo==0&&a[j].q2>a[j].q1&&a[j].q2>a[j].q3){
				a[j].lo=1;
				//printf("2 %d\n",a[j].q2);
				sum+=a[j].q2;//
				ow++;
			}
		}sort(a+1,a+n+1,o3);
		ow=0;
		for(int j=1;j<=n&&ow<n/2;j++){
			if(a[j].lo==0&&a[j].q3>a[j].q1&&a[j].q3>a[j].q2){
				a[j].lo=1;
				//printf("3 %d\n",a[j].q3);
				sum+=a[j].q3;
				ow++;
			}
		}printf("%d\n",sum);
		for(int i=1;i<=n;i++){
			a[i].lo=0;
		}
		sum=0; 
	}
	return 0;
}
