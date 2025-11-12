#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100000],q=0,e,l;
    cin>>n>>m;
    if(n==1&&m==1){
        cout<<1<<" "<<1;return 0;
    }
    for(int i=1;i<=m;i++)cin>>a[i];
    int w=a[1];
    sort(a+1,a+n+1);
    for(int i=m;i>=1;i--){
            q++;
        if(a[i]==w)break;
    }
    if(q%n==0){e=q/n;l=n;}  
    else {e=q/n+1;l=q%n;}
    cout<<e<<" ";
	if(e%2!=0)cout<<l;
	else{
		cout<<n-l+1;
	}
    return 0;
    fclose(stdin);
    fclose(stdout);
}
