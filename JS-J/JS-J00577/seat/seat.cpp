#include<bits/stdc++.h>
using namespace std;
struct student{
	int num,id;
}a[105];
bool cmp(student a,student b){
    return a.num>b.num;	
}
int n,m,k,h,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
	    if(a[i].id==1){
			k=i;
			break;
	    }	
	}
	if(k%n!=0){
		l=k/n+1;
		if(l%2!=0){
		    h=k%n;
	    }else{
			h=n-k%n+1;
	    }
    }else{
	    l=k/n;
	    if(l%2!=0){
			h=n;
	    }else{
			h=1;
	    }
    }

    cout<<l<<' '<<h;
    return 0;
}
