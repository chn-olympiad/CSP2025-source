#include<bits/stdc++.h> 
using namespace std;
int n,m,dy1,dy2,s,sum,c[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	int k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			scanf("%d",&c[k]);
			if(k==1){
				dy1=c[k];
			}
		}	
	}
	sort(c+1,c+1+k,cmp);
	for(int i=1;i<=k;i++){
		if(c[i]==dy1){
			dy2=i;
		}
	}
	s=dy2/n;
	if(dy2%n==0){
		if(s%2==1){
			printf("%d",s);
			cout<<" ";
			printf("%d",m);	
		}else{
			printf("%d",s);
			cout<<" ";
			m=1;
			printf("%d",m);
		}
	}else{
		if(s%2==0){
			dy2%=n;
			s++;
			printf("%d",s);
			cout<<" ";
			printf("%d",dy2);
		}else{
			s++;
			dy2%=n;
			printf("%d",s);
			cout<<" ";
			printf("%d",m-dy2+1);
		}	
	}
	
	return 0;
}
