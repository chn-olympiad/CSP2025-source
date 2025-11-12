#include<bits/stdc++.h>

using namespace std;
int n,q;
long long sum=0;
int c[105];
struct st
{
	int v,bj=0;
} a[1000005];
int er(int a, int b){
	int gh,cnt=0,sum=0;
	while(max(a,b)>0){
		gh=0;
		if(a%2==0) a/=2;
		else{
			a/=2;
			gh++;
		}
		if(b%2==0) b/=2;
		else{
			b/=2;
			gh++;
		}
		if(gh==1){
			c[++cnt]=1;
		}
		else c[++cnt]=0;
	}
	gh=0;
	for(int i = cnt; i>=1; i--){
		if(c[i]==1) gh=1;
		if(gh==1){
			if(c[i]==1) sum=sum*2+1;
			else sum*=2;
		}
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
 cin >> n >> q;
 for(int i = 1; i <= n; i++){
 	cin >> a[i].v;
 	if(a[i].v==q){
 		sum++;
 		a[i].bj=1;
	 } 
 }
 int gh;
 for(int i = 2; i<= n; i++){
 	for(int j=1; j+i-1<=n; j++){
 		if(a[j].bj==1) continue;
 		gh=a[j].v;
 		for(int k=j+1; k<=j+i-1; k++){
 			if(a[k].bj==1){
 				gh=-1;
 				break;
			 } 
 			gh=er(gh,a[k].v);
		 }
		 if(gh==q){
		 	sum++;
		 	for(int f=j; f<=j+i-1; f++){
		 		a[f].bj=1;
			 } 
		 }
	 }
 }
 cout << sum;
	return 0;
}
