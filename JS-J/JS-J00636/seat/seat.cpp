#include<bits/stdc++.h>
using namespace std;
int n,m,a[1145],pm=1,c,r;
int main(){
    //sto chen_zhe orzorz
    //sto kkksc03 orzorz
    //I love CCF!
    //RP++!
    //9:40
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(a[i]>a[0])pm++;
	}
	c=(pm+n-1)/n;
	if(c%2==0){
        r=n-(pm%n-1);
	}else{
	    if(pm%n==0)r=n;
	    else r=pm%n;
	}
	cout<<c<<' '<<r<<'\n';
	return 0;
}
//ni men de yi qie dou zai wo de zhang wo zhi zhong , ling zhen mo dao , wei mie yie tai chi le ba!
//zhu,bu zai hu
