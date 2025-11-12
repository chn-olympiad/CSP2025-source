#include<bits/stdc++.h>

using namespace std;

int n,m;

struct node{
	int a;
	int num;
}q[1000];

bool cmp(node x,node y){
	return x.a>y.a;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>q[i].a;
		q[i].num=i;
	}
	sort(q+1,q+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				//cout<<q[(i-1)*m+j].a<<i<<' '<<j;
				if(q[(i-1)*m+j].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}else if(i%2==0){
				//cout<<q[i*m+j-n].a<<i<<' '<<j;
				if(q[i*m-(n+1-j)].num==1){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
