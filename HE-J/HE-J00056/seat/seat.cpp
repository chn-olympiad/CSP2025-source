#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=1;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]) cnt++;
    }
    int t1=cnt/n;
    if(cnt%n!=0) t1++;
    cout<<t1<<" ";
    int t2=cnt-((t1-1)*n);
    if(t1%2==1) cout<<t2;
    else cout<<m-t2+1;
    cout<<endl;
	return 0;
}
