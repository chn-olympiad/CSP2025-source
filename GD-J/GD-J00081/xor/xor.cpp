#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],c[1000005],num=1,q;
struct node{
	long long x,y;
};
node p[1000005];
bool cmp(node a,node b){
	return a.y<b.y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1] xor a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((c[j] xor c[i-1])==m){
				p[++q].x=i;
				p[q].y=j;
			}
		}
	}
	if(q<=1){
		cout<<q;
		return 0;
	}
	sort(p+1,p+1+q,cmp);
	long long end=p[1].y;
	for(int i=2;i<=q;i++){
		if(p[i].x>end){
			num++;
			end=p[i].y;
		}
	}
	cout<<num;
	return 0;
}
