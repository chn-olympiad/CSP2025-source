#include<bits/stdc++.h>
using namespace std;
int n,r[5001],num=0;
void f(int m,int i,int sum,int max1){
	if(m==0){
		if(sum>max1*2){
			num++;
			num%=998;
			return;
		}
		else{
			return;
		}
	}
	for(int j=i;j<=n;j++){
		f(m-1,j+1,sum+r[j],max(max1,r[j]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int begin=1;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int m=3;m<=n;m++){
		f(m,1,0,0);
	}
	cout<<num;
	return 0;
} 
