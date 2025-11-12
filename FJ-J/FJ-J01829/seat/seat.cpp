#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    int a[110];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	int x=a[1];
	int haoshu=0;
	sort(a+1,a+m*n+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			haoshu=i;
			break;
		}
	}
	int h,l;
	l=ceil(haoshu/1.0/n);
	if(l&1){
		h=haoshu%n;
	}else{
		h=n-haoshu%n+1;
	}
	
	cout<<l<<" ";
	if(h==0){
		cout<<n;
		
	}else{
		cout<<h;
	}
	return 0;
}
