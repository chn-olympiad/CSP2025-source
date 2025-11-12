#include <bits/stdc++.h>
using namespace std;
long long n,k;
int a[500002];
int el[10];
int cnt1=0;
int cnt2=0;
int er[10];
void change1(int x){
	int t=x;
	while(t>=2){
		el[++cnt1]=t%2;
		t/=2;
	}
}
void change2(int x){
	int t=x;
	while(t>=2){
		er[++cnt2]=t%2;
		t/=2;
	}
}
int fun(int l,int r){
	int sum=0;
	change1(l);
	change2(r);
	int cnt=max(cnt1,cnt2);
	while(cnt){
		if(er[cnt] || el[cnt]) sum++; 
		cnt--;
	}
	for(int o=1;o<=cnt1;o++){
		el[o]=0;
	}
	for(int o=1;o<=cnt2;o++){
		er[o]=0;
	}
	cnt1=cnt2=0;
	return sum;
}
int ans=0;
long long qj(int i){
	int j;
	for(i=1;i<=n;++i){
		for(j=i;j<=n;++j){
			if(fun(i,j)==k){
				ans++;
			}
		}
	}
	if(n-j>0) {
		return qj(j+1);
	}
	else return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;++i){
    	scanf("%d",&a[i]);
	}
	printf("%d",qj(1));
	return 0;
}

