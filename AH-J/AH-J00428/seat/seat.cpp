#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000011];
long long nown,nowm,nowa;
int cmp(int x,int y){
		return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	nowa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==nowa){
			nowa=i;
		}
	}
	if(nowa%n==0){
		nown=n;
		nowm=nowa/n;
	}
	else {
		nown=nowa%n;
		nowm=nowa/n,nowm+=1;
		}
	
	if(nowm%2==0){
		if(nown==n){
			nown=1;
		}
		else {
			nown-=n,nown+=1;
			if(nown==0){
				nown=n;
			}
		}	
	}
	cout<<nowm<<" "<<nown;
    return 0;
}
//9:15 Open this problem.
//10:28 Read problem 3 min,i think hope is very big.
//10:34 Okey,i look a bug.
//10:45 Okey,i think T2 can AC!
