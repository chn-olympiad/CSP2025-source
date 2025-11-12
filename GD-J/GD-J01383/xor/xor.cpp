#include<bits/stdc++.h>
using namespace std;

long long cnt=0;
int num[500005],h[500005],pdn[500005],pd_[500005];//pdn判断是否有出现，pd_差分数组 
int n,k;
bool pd(int f,int e){
	for(int i=f+1;i<=e;i++){
		if(pdn[i]) return 0;
	}
	return 1;
}
void turn(){
	for(int i=1;i<=n;i++){
		pdn[i]=pdn[i-1]+pd_[i];
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		h[i]=h[i-1]^num[i];
	}
	
	int l=1,i=0;
	while(l<=n){
		while(i+l<=n){
			int a=h[i]^h[i+l];
			if(a==k&&pd(i,i+l)){
				++cnt;
				i+=l;
				pd_[i]++;
				pd_[i+l]--;
			}
			else ++i;
		}
		++l;
		i=0;
		turn();
		
	}
	cout<<cnt;
	return 0;
}



