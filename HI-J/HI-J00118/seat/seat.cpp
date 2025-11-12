#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],p=0;
int h,l=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int nm=n*m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int r=a[1];
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		if(p==1){
			if(h!=1) h--;
			else l++;
		}
		else{
			if(h!=n) h++;
			else l++;
		}
		if(l%2==0) p=1;
		else p=0;
		if(r==a[i]){
			printf("%d %d",l,h);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
