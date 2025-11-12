#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sum=0;
void ch(int num,int id,int sum1){
	
	for(int i=id+1;i<=n;i++){
		ch(num-1,i,sum1+a[i]);
	}
	
	if(num==0){
		if(sum1>a[id]*2){
			sum++;
		}
	}
}
void sort1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort1();
	for(int i=3;i<=n;i++){
		ch(i,0,0);
	}
	cout<<sum;
	return 0;
}
