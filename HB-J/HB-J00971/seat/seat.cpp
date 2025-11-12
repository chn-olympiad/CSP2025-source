#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,x,R,c=1,r=1,cnt=0;
	cin>>n>>m>>R;
	for(int i=1;i<n*m;i++){
        cin>>x;
        if(x>R){
            cnt++;
        }
	}
	for(int i=1;i<=cnt;i++){
        if(r==n&&c%2==1){
            c++;
        }else if(r==1&&c%2==0){
            c++;
        }else if(c%2==0){
            r--;
        }else{
            r++;
        }
	}
	cout<<c<<" "<<r;
	return 0;
}
