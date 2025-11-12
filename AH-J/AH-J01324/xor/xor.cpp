#include <bits/stdc++.h>
using namespace std;
const int MAX=10e5+5;
int a[MAX];
int cnt;
int main ()
{
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
    int k,n;
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >>a[i];
    }
    int x=1;
    while (x<=n){
		
        int temp=a[x]^a[x+1];
        if (temp==k&&x==1){
            cnt++;
            x++;
            continue;
         }
        if (a[x]==k){
            cnt ++;
            x++;
            continue;
        }
        for (int i=x+1;i<=n;i++){
            temp=temp^a[i];
            if (temp==k){
                cnt++;
                break;
            }
        }
        x++;
    }
    cout <<cnt;
    //esay~
	return 0;
}


