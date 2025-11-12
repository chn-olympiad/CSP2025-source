#include<bits/stdc++.h>
using namespace std;
struct num{
    int a;
    int b;
}a[10000];
bool cmp(num a,num b){
    return a.a>b.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i].a;
        a[i].b=i;
	}
    int ans;
	sort(a,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
        if(a[i].b==1){
            ans=i;
        }
    }
    if((ans/n+1)%2==1){
        cout<<ans/n+1<<" "<<ans%n+1;
        return 0;
    }
    cout<<ans/n+1<<" "<<n-(ans%n);
	return 0;
}
