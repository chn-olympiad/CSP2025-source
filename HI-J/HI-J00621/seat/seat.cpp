#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[100000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0,mark=0,hang=0,c,i1,j=-1;
	scanf("%d%d",&n,&m);
	for(long long i=0;i<n*m;i++){
		scanf("%d",&b[i]);
	}
	mark=b[0];
	c=n*m;
	sort(b+0,b+c+1,cmp);
	
	for(long long i=0;i<=c;i++){
		i1=i+1;
		if(i%n==0)j++;
		if(mark==b[i]){
			if(j%2==0){
				if(i1==n)hang=n;
				else hang=i1%n;
			}
			if(j%2!=0){
				if(i1%n==0)hang=1;
				else {
					if(n!=0){
						i1=i1%n;
					}
						hang=n-i1%n+1;
				}
			}
			break;
			
		}
	}
	printf("%d %d",j+1,hang);
	return 0;
}
