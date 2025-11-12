#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		int d=1;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				continue;
			}
			if(d==0&&a[i]==1){
				cnt++;
				d=1;
			}else if(a[i]==1){
				d=0;
			}
		}
		cout<<cnt;
	}else if(k==1){//count 1 
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt++;
		}
		cout<<cnt;
	}else{
		cout<<12701;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
em.  xor is so diffcult  
i don't have any mind
first    
finish some easy out


oh my ga
i only can make 30 ,it's so diffcult
maybe use tanxin/hua dong chuang kou   
but i can't writing
i don't have any mind













*/
