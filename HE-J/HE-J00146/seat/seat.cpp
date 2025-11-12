#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    long long b[1000];
    int h=0,l=0;
    int ans=1;
    for(int i=1;i<=n*m;i++){
        cin >> b[i];
        if(b[1]<b[i]){
			ans+=1;
		}
    }
    	if(ans%n!=0){
        l=ans/n+1;
    }
    if(ans%n==0){
        l=ans/n;
    }
    if(l==1){
    	h=ans;
	}
    if(l%2==1){
        h=0+ans%n;
    }
    if(l%2==1&&ans%n==0){
        h=0+n;
    }if(l%2==0){
        h=n-ans%n+1;
    }
    if(l%2==0&&ans%n==0){
        h=0+1;
    }
    cout << l << " " << h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
