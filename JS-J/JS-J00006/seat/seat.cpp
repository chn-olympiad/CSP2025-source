#include<bits/stdc++.h>
#define ll long long
#define N 100
using namespace std;
int n,m,p,s;
int a[N*N];
int u(int x,int y){
    if(x/y*y==x) return x/y;
    else return x/y+1;
}
int q(int x,int y){
    if(x%y==0){
        return y;
    }else{
        return x%y;
    }
}
int bi(){
    int l=1,r=n*m,mid;
    while(l<=r){
        mid=(r+l)>>1;
        if(a[mid]==s){
            return mid;
        }
        if(a[mid]>s){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }return mid;
}
void init(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
        cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m);
	p=m*n-bi()+1;

	//cout<<p<<endl;
	//cout<<u(p,n)<<endl;

    if(u(p,n)&1){
        cout<<u(p,n)<<' '<<q(p,n);
    }else{
       cout<<u(p,n)<<' '<<n-q(p,n)+1;
    }
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
