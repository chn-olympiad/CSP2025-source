#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,r,n,t=1,hang,lie;
	scanf("%d%d",&a,&b);
	int m[a*b+1];
	scanf("%d",&m[1]);
	r=m[1];
	for(int i=2;i<=a*b;i++){
	scanf("%d",&m[i]);	
	if(m[i]>r){
		t++;
	}
	}
	hang=t%a;
	if(hang==0){
		hang=a;
	}
	lie=(t-hang)/a+1;
	if(lie%2==0){
		hang=a+1-hang;
	}
	printf("%d %d",lie,hang);
	fclose(stdin);fclose(stdout);
	return 0;
}
