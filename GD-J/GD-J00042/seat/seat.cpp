#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt[105],me,sum,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&me);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}for(int i=100;i>=me;i--){
		sum++;
	}c=ceil(sum*1.0/n);
	if(c%2){
		if(sum%n){
			r=sum%n;
		}else{
			r=n;
		}
	}else{
		if(sum%n){
			r=n+1-sum%n;
		}else{
			r=1;
		}
	}printf("%d %d",c,r);
} 
