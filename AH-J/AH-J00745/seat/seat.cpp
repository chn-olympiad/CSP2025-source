#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>x;
	a[1]=x;
	int len=n*m,num;
	for(int i=2;i<=len;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		if(a[i]==x){
			num=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				num--;
				if(num==0){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				num--;
				if(num==0){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
