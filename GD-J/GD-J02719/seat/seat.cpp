#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=107;
int n,m,a[N],t[N];

bool cmp(int x,int y){
	return a[x]>a[y];
}

int main(){
	freopen("seat.in" ,"r",stdin );
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i],t[i]=i;
	
	sort(t+1,t+n*m+1,cmp);
	for(int i=1,xx=1,yy=1;i<=n*m;i++){
		if(t[i]==1){
			cout<<xx<<" "<<yy;
			return 0; 
		}
		if((xx%2==1&&yy==n)||(xx%2==0&&yy==1)) xx++;
		else{
			if(xx%2==1) yy++;
			else yy--;
		}
	}
	
	return 0;
}

