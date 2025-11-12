#include<bits/stdc++.h>
using namespace std;
int a[210],n,m,x=1,y=1,sum,cnt;
bool f=true;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    cnt=n*m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    sum=a[1];
    sort(a+1,a+1+n*m);
    while(a[cnt]!=sum){
    	if(f){
    		if(x<n) x++;
    		else{
    			y++;
    			f=false;
			}
		}
		else{
			if(x>1) x--;
			else{
				y++;
				f=true;
			}
		}
		cnt--;
	}
	cout<<y<<' '<<x;
	return 0;
}
