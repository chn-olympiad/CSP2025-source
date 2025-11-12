#include<bits/stdc++.h>
using namespace std;
int n,m;
int A[105],a1;
int num;
bool cmp(int a,int b){
	if(a>b) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&A[i]);
	}
	a1=A[1];
	sort(A+1,A+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(A[i]==a1){
			num=i;
			break;
		}
	}
	int i=(num-1)/n+1;
	int j=num%n;
	if(j==0) j=n;
	if(i%2==0) j=n-j+1;
	printf("%d %d",i,j);
	return 0;
}
