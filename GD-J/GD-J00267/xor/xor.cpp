#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

bool A=true,B=true;
int n,k,a[N];
struct X{
	int l,r;
}b[N*20];
int t=0;
int query[N];
int get_w(int l,int r){
	return query[r] xor query[l-1];
}
bool cmp(X tx,X ty){
	return tx.r<ty.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		query[i]=query[i-1] xor a[i];//前缀和数组
//		cout<<i<<':'<<query[i]<<endl;
		
		if(a[i]!=1) A=false;
		if(a[i]!=1&&a[i]!=0) B=false;
	}
	
	if(A){
		printf("%d",n/2);
		return 0;
	}//性质A 
	if(B){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			printf("%d",sum);
		}
		if(k==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					sum++;
					i++;
				}
				if(a[i]==0){
					sum++;
				}
			}
			printf("%d",sum);
		}
		return 0;
	}//性质B 
	//以下为通解 60分 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(get_w(j,i)==k){
//				cout<<get_w(j,i)<<' '<<j<<' '<<i<<endl;
				b[++t]={j,i};
			}
		}
	}
	sort(b+1,b+t+1,cmp);
//	for(int i=1;i<=t;i++){
//		cout<<b[i].l<<' '<<b[i].r<<endl;
//	}
	int sum=0;
	for(int i=1;i<=t;){
		int tail=b[i].r;
		sum++;
		while(i++){
			int head=b[i].l;
			if(head>tail){
				break;
			}
		}
	}
	printf("%d",sum);
	return 0;
}
/*
自测样例
性质A checked 
10 0
1 1 1 1 1 1 1 1 1 1
性质B checked 
10 1
0 1 1 0 1 0 1 1 0 0
0 1 1 0 1 1 0 1 0 0
1 0 1 1 0 0 1 1 1 0

4 0
2 1 0 3
4 3
2 1 0 3
60分++ 保二等 
*/
