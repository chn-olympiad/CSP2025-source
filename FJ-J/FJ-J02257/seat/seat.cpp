#include <bits/stdc++.h>
using namespace std;
//c:列   r:行 
int c,r,sum=0,k=0;
int cntc=1,cntr=1,cntr1=cntr;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	sum=c*r;
	for(int i=1;i<=sum;i++) cin>>a[i];
	int num=a[1];
	sort(a+1,a+sum+1,greater<int>());
	for(int i=1;i<=sum;i++){
		if(a[i]==num) k=i;
	}
	//c:列    r:行 
	for(int i=1;i<=sum;i++){
		if(i==k){
			cout<<cntc<<' '<<cntr;
			return 0;
		}
		else{
			if(i%r==0){
				cntc++;
				if(cntc==i+1&&cntr==r){
					cntr1=cntr;
					cntr=r;
					cntr--;	
				}
				if(cntc==i+1&&cntr==1){
					cntr1=cntr;
					cntr=1;
					cntr++;
				}
			}
			else{
				if(cntr1>cntr) cntr--;
				if(cntr1<cntr) cntr++;
				if(cntr1==cntr) cntr++;
			}
		}	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
