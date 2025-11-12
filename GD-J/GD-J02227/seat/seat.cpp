#include<bits/stdc++.h>
using namespace std;

int n,m;

struct node{
	int s,b;
}a[105];

bool cmp(node x,node y){
	return x.s>y.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i].s,a[i].b=i;
	sort(a+1,a+1+n*m,cmp);
	int idx=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++){
			if(a[idx].b==1){
				if(i%2==1)
					cout<<i<<" "<<j<<endl;
				else
					cout<<i<<" "<<j%n+1<<endl;
			}
			idx++;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
