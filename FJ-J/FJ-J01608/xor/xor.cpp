#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],t[500010],ans=0,x,y=0;
bool b[500010],q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=true;
	}
	for(int i=1;i<=n;i++){
		x=i;
		y=0;
		int l=0;
		t[0]=a[i];
		if(t[0]==k){
			y=i;
		}
		else{
			for(int j=i+1;j<=n;j++){
				t[++l]=t[l-1] xor a[j];                                                                                                                                                                                                                                                                                    
				if(t[l]==k){
					y=j;
					break;
				}
			}	
		} 
		if(y!=0){
			q=false;
			for(int j=x;j<=y;j++){
				if(b[j]==false){
					q=true;
				}
				if(b[j]==true){
					b[j]=false;
				}
			}
			if(!q){
				ans++;
			}
			else {
				for(int j=x;j<=y;j++){
					b[i]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
