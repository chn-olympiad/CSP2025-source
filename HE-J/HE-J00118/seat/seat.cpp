#include<bits/stdc++.h>
using namespace std;

int a[1000];
int n,m;
int w;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	w=n*m;
	for(int i=1;i<=w;i++)
		scanf("%d",&a[i]);
	int p=a[1];
	sort(a+1,a+1+w);
	int ps;
	for(int i=1;i<=w;i++)
		if(a[i]==p)
			ps=w-i+1;
	int w1,w2;
	w1=ps/(n*2)*2;
	w2=ps-(w1*n);
	if(w2>n){
		w1+=1;
		ps-=n;
		printf("%d %d",w1+1,n-ps+1);
	}else{
		if(w2!=0)
			printf("%d %d",w1+1,w2);
		else
			printf("%d %d",w1,1);
	}
	
	return 0;
}
