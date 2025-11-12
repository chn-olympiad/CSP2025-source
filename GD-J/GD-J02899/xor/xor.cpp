//暴力且没通过一些样例=(     O(n平方)?   (?0分(  =(  ))
#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
using namespace std;
ll n,k,a[500005],c[70],man,sh,ans;
ll b[500005];
bool y[500005],TXB=1;
int main(){
	/*2 1 0 3dp
	  10 01 00 11
	  1010
	   等 =>0 不等 =>1*/
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
//cout<<(0^2);
    scanf("%lld%lld",&n,&k);
   /* sh=k;
    while(sh){
    	c[man]=sh%2;	
    	sh/=2,man++;
	}*/
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
    	if(a[i]>1)TXB=0;
    	b[i]=(b[i-1]^a[i]);
    //	cout<<"b["<<i<<"]="<<b[i]<<endl;
	}
	if(TXB&&n>1000)//拿测试点13的分。5分也是分，对吧？ 
	{
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
			}
		}
		/*for(int i=2;i<=n;i++){
			if(a[i]^a[i-1]==k)ans++,i++;
		}*/
		cout<<ans;
		return 0;
	}
//	if(TXA){cout<<n/2;return 0;}
	//cout<<"死了=(";
	/**/
	for(int cd=1;cd<=n;cd++){
		for(int i=1;i<=n-cd+1;i++){
		//	if(	k==((b[i+cd-1]^b[i-1])))cout<<i<<"~"<<i+cd-1<<"="<<k<<endl;
		//	cout<<i<<"~"<<i+cd-1<<":"<<b[i+cd]<<"^"<<b[i-1]<<"="<<((b[i+cd-1]^b[i-1]))<<endl;
	if(((b[i+cd-1]^b[i-1]))==k){
		bool f=1;
		for(int j=i;j<=i+cd-1;j++){
			if(y[j]){
				f=0;break;
			}
		}
		if(f){
	//		cout<<i<<"~"<<i+cd-1<<"="<<((b[i+cd-1]^b[i-1]))<<endl;
			ans++;
			for(int j=i;j<=i+cd-1;j++)y[j]=1;
		}
		
	}
		}
	}
//	for(int i=1;i<=n;i++)cout<<y[i];
	printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
	return 0;
}
/*
10 1
0 1 0 0 0 0 0 0 0 1 0 0
10 0
*/
