#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[10001],b,c,j=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+(n*m)+1);
    for(int i=n*m;i>=1;i--){
    	j++;
		if(a[i]==b)c=j;
	}
    if(c%m!=0&&(c/m+1)%2==1){
        cout<<c/m+1<<' '<<c-c/m*m;
    }else if(c%m!=0&&(c/m+1)%2==0){
        cout<<c/m+1<<' '<<m;
    }else if(c/m%2==1){
        cout<<c/m<<' '<<m;
    }else{
        cout<<c/m<<' '<<1;
    }
    return 0;
}
