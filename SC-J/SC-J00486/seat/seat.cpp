#include<bits/stdc++.h>
using namespace std;
int cnt,n,m,c,r;
struct node{
	int v,id;
}cj[105];
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cj[++cnt].v;
			cj[cnt].id=(i-1)*m+j;
		}
	}
	sort(cj+1,cj+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(cj[i].id==1){
			c=ceil(i*1.0/n);
			if(c%2==0){
				if(i%n==0){
					r=1;
					break;
				}
				else{
					r=n-i%n+1;
                    break;
				}
			}
			else{
				if(i%n==0){
					r=n;
					break;
				}
				else{
					r=i%n;
                    break;
				}
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}