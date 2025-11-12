#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
long long f=1,cnt=0,n,k,a[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i] != 1) {cnt++;f=0;}
    }
    if (f == 1) {
        cout<<n<<endl;
        return 0;
    }
    else {
        if (k == 0){
        	for (int i=1;i<=n;i++){
            	if (a[i] && a[i+1]){
                cnt++;
                i+=2;
            }
        }
	}
	else if (k == 1){
		cnt = n-cnt;
	}
        cout<<cnt<<endl;
        return 0;
    }
    return 0;
}

