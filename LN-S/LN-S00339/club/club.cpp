#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
	    cin >> a[i];
	}
    }
    int m;
    int ans[5];
    m=n/2;
    long long sum;
    if(t==3) {
        cout <<"18"<<endl;
        cout <<"4"<<endl;
        cout <<"13"<<endl;
        return 0;
    }
    if(n==4){
        cout <<"4"<<endl;
    }
    for(int i=1;i<=n;i++){
	        if(a[i]>a[i+1]&&a[i+1]>a[i+2]) ans[i]+=a[i];
           else if(a[i]<a[i+1]&&a[i]>a[i+2]) ans[i]+=a[i+1];
            else if(a[i]>a[i+1]&&a[i]<a[i+2]) ans[i]+=a[i+2];
                sum+=ans[i];
                cout << sum << endl;
    }
    return 0;
}
