#include<bits/stdc++.h>
using namespace std;
int n,k,num;
int zejz(int a){
	int b=0,ll=1;
	while(a){
		 b+=ll*(a%2);
		 a/=2;
		 ll*=10;
	}
	return b;
}
int zshi(int a){
	int b=0,ll=1;
	while(a){
		b+=ll*(a%10);
		a/=10;
	}
	return b;
}
int yhh(int a,int b){
	int c=0,ll=1;
	while(a||b){
		if(!(a%10==b%10))
			c+=ll;
		ll*=10;
		a/=10; b/=10;
	}
	return c;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	k=zejz(k);
	int a[n+5],b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=zejz(a[i]);
	}
	int lkj=1,sadd=1,aaa;
	while(lkj){
		lkj=0;
		for(int i=sadd;i<=n;i++){
			aaa=0;
			for(int j=sadd;j<=i;j++){ 
				aaa=yhh(aaa,b[j]);
				if(aaa==k){
					num++;
					lkj=1;
					sadd=i+1;
					break;
				}
			}
		} 
	}
	cout<<num;
	return 0;
}


//这道题做不出来了，保佑我别的题目可以做对吧
//披萨摸砸雷拉~ 披萨摸砸雷拉~  
//这是我最后一次考试了 ，jojo，收下吧！ 
//赛高泥high铁鸭子哒！！！ 
//不对，好像做出来了！
//aaaaaa qwq!加油吧！
//一起合作吧 
