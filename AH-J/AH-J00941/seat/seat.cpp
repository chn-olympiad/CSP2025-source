#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int z=n*m;
    for(int i=1;i<=z;i++) cin>>a[i];
    int x=a[1];
    sort(a+1,a+z+1);
    int jl;
    for(int i=1;i<=z;i++){
		if(a[i]==x){
			jl=i;
			break;
		}
	}
	jl=z+1-jl;
	c=(jl-1)/n+1;
	if(c%2==1) r=(jl-1)%n+1;
	else {
		r=n+1-((jl-1)%n+1);
	}
	cout<<c<<" "<<r;
    return 0;
} 
