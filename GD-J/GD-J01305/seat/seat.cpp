#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return b<a;
}
int n,m,sum,x,y;
int a[120];
void find(int id){
	int p=1,l=1;
	while(p!=id){
		if((l==1&&(y+1<=n))||(l==-1&&(y-1>=1))){
			y+=l;
		}else{
			l*=-1;
			x++;
		}
		p++;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>sum;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	int head=0;
	while(a[++head]>sum){}
	x=1;
	y=1;
	find(head);
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
