#include<bits/stdc++.h>

using namespace std;

const int N=105;
int a[N];
int n,m,k=0;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int start;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			scanf("%d",&a[k]);
			if(k==1){
				start=a[1];
			}
		}
	}
	
	sort(a+1,a+k+1,cmp);
	int id=-1;
	for(int i=1;i<=k;i++){
		if(a[i]==start){
			id=i;
			break;
		}
	}
	
	int cur=id,op=0;
	for(int i=1;i<=m;i++){
		if(cur<=n){
			if(op==0){
				printf("%d %d\n",i,cur);
				return 0;
			}
			else{
				printf("%d %d\n",i,n-cur+1);
				return 0;
			}
		}
		cur-=n;
		op^=1;
	}
	
	return 0;
}
