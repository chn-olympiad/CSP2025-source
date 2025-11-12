#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,len;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    len=n*m;
    for(int i=1;i<=len;i++)
        cin>>a[i];
    int f=a[1],id=0;
    sort(a+1,a+1+len,cmp);
    for(int i=1;i<=len;i++)
        if(a[i]==f){
			id=i;
			break;
		}
	int fid=id%m;
    if(((id-1)/m+1)%2==1){
		if(fid==0) fid=m;
		cout<<(id-1)/m+1<<' '<<fid;
	}
	else cout<<(id-1)/m+1<<' '<<m-fid+1;
    return 0;
}
