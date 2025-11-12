#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N];
int b[409][409];
struct node{
	int x,y;
}; 
node c[N];
bool cmp(node a,node b){
	if(a.y!=b.y){
		return a.y<b.y;
	}
	else{
		return a.x<b.x;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			for(int i=l;i<=r;i++){
				b[l][r]^=a[i];
			}
			if(b[l][r]==k){
				c[cnt].x=l;
				c[cnt].y=r;
				cnt++;	
			}
		}
	}
	sort(c+1,c+cnt,cmp);
	int ans=0;
	int l=0,r=0; 
	for(int i=1;i<cnt;i++){
		if(c[i].x>r){
			ans++;
			l=c[i].x;
			r=c[i].y;
		}
	}
	cout<<ans;
	return 0;
}
