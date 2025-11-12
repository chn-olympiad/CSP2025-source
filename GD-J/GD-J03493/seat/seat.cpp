#include<bits/stdc++.h>
using namespace std;
const int N=105;
bool ff;
int n,m;
int s;
int g;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		scanf("%d",&a[i]);
	}
	g=a[1];
	sort(a+1,a+1+s,cmp);
	r=1,c=1;
	for(int i=1;i<=s;i++){
		if(a[i]==g){
			cout<<c<<" "<<r;
			break;
		}
		if(r==n&&ff==0){
			c++;
			ff=1;
		}
		else if(r==1&&ff==1){
			ff=0;
			c++;
		}
		else if(ff==0){
			r++;
		}
		else{
			r--;
		}
	}
	return 0;
} 
