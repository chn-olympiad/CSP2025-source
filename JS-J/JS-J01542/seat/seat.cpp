#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005],c,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,cmp);
    int s=1;
    bool f=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[s]==x){
					cout<<i<<" "<<j;
					f=0;
				}
                s++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[s]==x){
					cout<<i<<" "<<j;
					f=0;
				}
                s++;
            }
        }
        if(!f){
			break;
		}
    }  
    return 0;
}
