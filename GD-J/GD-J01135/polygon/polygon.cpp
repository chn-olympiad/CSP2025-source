#include<bits/stdc++.h>
using namespace std;
int a[5100];
bool flag[5100];
int num=3,n;
int sum=0;
int check(){
	int lsum=0;
	for(int i=1;i<=n;i++){
		if(flag[i]==1){
			lsum++;
		}
	}
	if(lsum!=num)return 0;
	else return 1;
}
void found(int time,int maxn,int l){
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			if(time==num+2){
				if(l>2*maxn&&check()){
					sum++;
				}
			}else{
				found(time+1,max(maxn,a[i]),l+a[i]);
			}
		}
		flag[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		num=i;
		found(1,0,0);
	}
	cout<<sum;
	return 0;
} 
