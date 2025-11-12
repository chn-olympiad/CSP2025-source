#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool b[10005];
int n,k;
int cnt=0;
void fd(int x,int y){
	if(x>y)return;
	for(int i=1;i+x-1<=n;i++){
		int df=false;
		for(int j=i;j<=i+x-1;j++){
			if(b[j]==true){
				df=true;
			}
		}
		
		if(df==false){
			int xa=a[i];
			for(int j=i+1;j<=i+x-1;j++){
					xa=xa^a[j];
		    }
		    if(xa==k){
		    	cnt++;
		    	for(int j=i;j<=i+x-1;j++){
		    		b[j]=true;
				}     
			}
		}
	} 
	int mx=0;
	int sw=0;
	for(int i=1;i<=n;i++){
		if(b[i]==false){
			sw++;
		}else{
			mx=max(mx,sw);
			sw=0;
		}
	}
	mx=max(mx,sw);
	fd(x+1,mx);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fd(1,n);
	cout<<cnt;
	return 0;
}
