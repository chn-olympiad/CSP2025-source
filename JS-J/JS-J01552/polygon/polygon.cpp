#include<bits/stdc++.h>
using namespace std;
int vis[5000],a[5000];
long long s;
int n;
void d(int i,int x,int y,int z){
	for(int j=z;j<=n;j++){
		if(vis[j]==0){
			if(i==0){
				if(x>y*2){
					s++;
				}
			}
			else{
				vis[j]=1;
				d(i-1,x+=a[j],max(y,a[j]),j);
				vis[j]=0;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int x=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
			x=0;
		}
    }
    if(x){
		cout<<0;
		return 0;
	}
    else if(n==3){
		int b=a[1]+a[2]+a[3];
		int c=max(a[3],max(a[1],a[2]));
		if(b<=c*2)
			cout<<0;
		else{
			cout<<1;
		}
		return 0;
	}
	else{
		for(int i=3;i<=n;i++){
			d(i,0,0,1);
		}
		cout<<s%998%244%353;
	}
}
