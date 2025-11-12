#include <bits/stdc++.h>
using namespace std;
int n,t,m=0;
struct f{
	int yi,er,san,ma;
};
f a[100000];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t){
	    cin>>n;
		for(int i=1;i<=n;i++){
		    cin>>a[i].yi>>a[i].er>>a[i].san;
		    a[i].ma=max(a[i].yi,a[i].er);
		    a[i].ma=max(a[i].ma,a[i].san);
		    m=m+a[i].ma;
		}
		cout<<m;
	}
	
    return 0;
}
