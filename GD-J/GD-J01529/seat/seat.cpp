#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int x=a[1],t;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	puts("");
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			t=i;
			break;
		}
	}
	int p=t%m,q;
	
	if(!p){
		q=t/m;
		p=m;
	}
	else{
		q=t/m+1;
	}
//	cout<<p<<" "<<q<<endl;
	if(q%2==0){
		printf("%d %d",q,m-p+1);
	}
	else{
		printf("%d %d",q,p);
	}
	return 0;
}
/*
2 2
98 99 100 97

2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/
