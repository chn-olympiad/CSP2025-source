#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a1,a[N];
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int len=n*m,k=0;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i]);
		if(i==1) a1=a[i];
	}
	sort(a+1,a+len+1,cmp);
	
	bool f=false;
	for(int j=1;j<=m;j++){
		if(j%2){
			for(int i=1;i<=n;i++){
				if(a[++k]==a1){
					printf("%d %d\n",j,i);
					f=true;
					return 0;
				}
			}
		}else{
			for(int i=n;i>=1;i--){
				if(a[++k]==a1){
					printf("%d %d\n",j,i);
					f=true;
					return 0;
				}
			}
		}
		if(f) break;
	}
	return 0;
}
