#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5005;
int a[N],r[N];
int k=0;

bool check (int y){
	for(int i=1;i<=k;i++){
		if(y==r[i]) return false;
	}return true;
}

void chet (){
	
	for(int i=1;i<=n;i++){
		if(check(i)){
			r[++k]=i;
			
		}
	}
}

long long sum=0;

void node(){
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);	
	
	int e=n;
	while(e--){
		memset(r,0,sizeof(r));
		for(int i=1;i<=e;i++){
			chet();
		}
		
		node();
		
	}
	cout<<n*2-1;
	return 0;
	
}
