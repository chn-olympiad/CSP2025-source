#include<bits/stdc++.h>
using namespace std;
int n,m,p,a[1005],l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
        cin>>n>>m;
        cin>>a[1];
        p=a[1];
        for(int i=2;i<=n*m;i++){
        	cin>>a[i];
		}
		sort(a+1,a+n*m+1);
		for(int i=n*m;i>=1;i--){
		//	cout<<a[i]<<" ";
        	if(a[i]==p){
        		//cout<<i<<" ";
        		l=n*m-i;
        		break;
			}
	}
		int x=1,y=1,d=0;
	//	cout<<l<<" ";
		while(l--){
			if(d==0){
				y++;
			}else{
				y--;
			}
			if(y==m+1&&d==0){
				x++;
				d=1;
				y=m;
			}
			if(y==0&&d==1){
				x++;
				d=0;
				y=1;
			}
		}
		cout<<x<<" "<<y;
	return 0;
}
