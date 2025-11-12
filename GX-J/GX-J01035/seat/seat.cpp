#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	int value;
}a[505];
bool cmp(node d,node e){
	return d.value>e.value;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[(i-1)*m+j].value;
			a[(i-1)*m+j].x=i;
			a[(i-1)*m+j].y=j;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int x1=0,y1=1,s1=0;
	for(int i=1;i<=n*m;i++){
		if(s1==0)x1++;
		else if(s1==1)x1--;
		if(i%n==1&&i!=1&&i%(2*n)!=1){y1++;x1--;s1=1;}
		if(i%(2*n)==1&&i!=1){y1++;x1++;s1=0;}
		if(a[i].x==1&&a[i].y==1){
			cout<<y1<<" "<<x1;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
