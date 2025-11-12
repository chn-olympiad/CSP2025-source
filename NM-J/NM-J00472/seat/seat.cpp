#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	if(a>=100){
		return a>b;
	}
	if(b>=100){
		return b>a;
	}
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    int t=0,w=n*m;
    for(int i=1;i<=w;i++){
        cin>>a[i];
    }
	t=a[1];
    sort(a,a+w,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            t=i;
            break;
        }
    }
	w=(t-1)/n+1;
	cout<<w<<" ";
	if(w%2==1){
		if(t%n==0){
			cout<<n;
			return 0;
		}
		cout<<t%n;
	}else{
		if(t%n==0){
			cout<<1;
			return 0;
		}
		cout<<n+1-t%n;
	}

    return 0;
}
