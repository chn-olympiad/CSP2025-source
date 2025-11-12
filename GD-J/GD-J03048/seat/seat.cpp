#include<bits/stdc++.h>

using namespace std;
int a[10010];
bool cnp(const int& a,const int& b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++t];
		}
	}
	int k=a[1];
	sort(a+1,a+1+t,cnp);
	int x=1,y=1;
	int h=1;
	int ok=0;
	for(int i=1;i<=t;i++){
		if(a[i]==k){
			cout<<x<<" "<<y;
			return 0;
		}
		if(y==m&&i!=1&&ok==1||y==1&&i!=1&&ok==1){
			x+=1;
			h=(h+1)%2;
			ok=0;
		}else if(h==1){
			y+=1;
			ok=1;		
		}else{
			y-=1;
			ok=1;
		} 
	}
	
	return 0;
}
