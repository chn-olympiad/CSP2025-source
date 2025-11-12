#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int K=20;
int n,k,a[N],ans;
bool f1=true,f2=true;
void solve1(){
	if(k>1) printf("0");
	else if(k) printf("%d",n);
	else printf("%d",n/2);
}
void solve2(){
	if(k>1) printf("0");
	else if(k){
		for(int i=1;i<=n;i++)	
			if(a[i]) ans++;
		printf("%d",ans); 
	}else{
		int s=0;
		for(int i=1;i<=n;i++)
			if(a[i]) s++;
			else{
				ans+=s/2;
				s=0;ans++;
			}
		ans+=s/2;
		printf("%d",ans);
	}
}
void solve3(){
	for(int i=1;i<=n;i++)
		if(a[i]==k) ans++;
	printf("%d",ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) f1=false;
		if(a[i]>1) f2=false;
	}if(f1&&f2) solve1();
	else if(f2) solve2();
	else solve3();
	return 0;
}
