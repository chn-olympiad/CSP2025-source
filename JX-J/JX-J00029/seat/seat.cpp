#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a,t,num=1;
	scanf("%d",&a);
	for(int i=0;i<n*m-1;i++){
		scanf("%d",&t);
		if(t>a) num++;
	}
	int i=1,j=1,sum=1;
	bool p=0;
	while(1){
		num--;
		if(!num){
			printf("%d %d",i,j);
			break;
		}
		if(sum==m){
			if(p) p=0;
			else p=1;
			i++;
			sum=1;
		}else{
			if(!p) j++;
			else j--;
			sum++;
		}
	}
	return 0;
}
