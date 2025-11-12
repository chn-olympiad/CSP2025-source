#include<bits/stdc++.h>
using namespace std;
int xing(int q){
	int w[q];
	int cnt=0;
	for(int i=1;i<=q;i++){
		cin>>w[i];
		cnt+=w[i];
	}
	sort(w+1,w+q);
	if(w[q]*2<cnt) return 1;
	if(w[q]*2>=cnt) return 0;
}

int main(){
	feropen("polygon.in","r",stdin);
	feropen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5005];
	int p=3;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	return 0;
}
