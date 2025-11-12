#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[5001000];
bool flaga=true,flagb=true;
int cnt1,cnt0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k!=0){
		flaga=false;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}
		if(a[i]==0){
			cnt0++;
		}
		if(a[i]!=1){
			flaga=false;
			//cout<<1;
		}
		if(a[i]!=1&&a[i]!=0){
			flagb=false;
			//cout<<2;
		} 
	}
	//cout<<flagb<<"&";
	//cout<<cnt0<<" "<<cnt1;
	if(flaga==true){
		cout<<n/2;
		exit(0);
	}	
	if(flagb==true){
		if(k==1){
			cout<<cnt1;
			exit(0);
		}else if(k==0){
			cout<<cnt0+cnt1/2;
			exit(0); 
		}
	}
	return 0;
}
 // 1 1 1 0 0 0 1
 //5 0 1 0 1 1 0
 //9:39 A性质 10pts
 //10:11 发现读错题了 
 //10:13 改A性质 10pts
 //10:24 B性质 30pts
//10:47 骂自己两句 (跳t4) 
//11:32 检查出性质B错误 