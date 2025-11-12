#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
long long n,m,a[101],sum,ii=1,jj;
bool offorno;
bool s(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];//emm......我忘了那个怎么写了
	sort(a+1,a+n*m+1,s);
	for(int i=1;i<=n*m;i++){
		if(offorno==0){
			jj++;
			if(jj==n+1){
				ii++;
				jj=n;
				offorno=1;
			}
		}else{
			jj--;
			if(jj==0){
				ii++;
				jj=1;
				offorno=0;
			}
		}
		if(a[i]==sum){
			cout<<ii<<" "<<jj;
			return 0;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
