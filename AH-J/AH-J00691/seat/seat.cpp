#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int q=n*m;
    int a[q]={0};
    for(int i=0;i<q;i++){
		cin>>a[i];
	}
	int e=a[0];
	sort(a,a+q,cmp);
	for(int i=0;i<q;i++){
		if(a[i]==e){
			e=i;
			break;
		}
	}
	int y=e/n+1,x;
	if(y%2==1){
		x=e%n+1;
	}
	else{
		x=n+1-(e%n+1);
	}
	cout<<y<<' '<<x;
    return 0;
}
