#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int a[500005];
int n,ans=0;

void dfs(int m,int ma,int c,int y){
	if(m==n){
		ans=ans%998244353;
		if(ma*2<c&&y>=3){ans++;
		//	cout<<y<<" "<<ma<<" "<<c<<endl;
			}else{
		//    cout<<"no "<<y<<" "<<ma<<" "<<c<<endl;
			}
		return;
		};
	for(int i=0;i<2;i++){
		if(i){
			dfs(m+1,ma,c,y);
			}else{
				if(a[m]>ma)dfs(m+1,a[m],c+a[m],y+1);else
				dfs(m+1,ma,c+a[m],y+1);
			}
		}
	}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>a[i];
		}
		dfs(0,0,0,0);
		cout<<ans;
    return 0;
   
}
