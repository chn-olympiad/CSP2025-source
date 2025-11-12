#include<bits/stdc++.h>
using namespace std;
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num;
	scanf("%d %d",&n,&m);
	int a[n*m];
	for(int i=0;i<n*m;i++){
		scanf("%d",&a[i]);
	}
	num=a[0];
	sort(a,a+n*m,f);
	for(int i=0;i<n*m;i++){
		if(a[i]==num){
			//cout<<i+1<<endl;
			int ttmp=((i+1)+n-1)/n,tmp;
			if(ttmp&1){
				tmp=(i+1)%(2*n);
			}
			else{
				if((i+1)%n==0)tmp=1;
				else tmp=n+1-((i+1)%n);
			}
			printf("%d %d",ttmp,tmp);
		}
	}
	return 0;
}
