#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define PII <int,int>
using namespace std;
const int N=1e5+10;
int a[110];
int n,m,x,cnt;
bool flag=true;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cnt=m*n;
	for(int i=1;i<=cnt;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+cnt+1);
    for(int i=1;i<=m;i++){
        if(flag){
            for(int j=1;j<=n;j++){
                if(a[cnt--]!=x) continue;
                else{
                    cout<<i<<" "<<j;
                    return 0;
                }
            }flag=false;
        }
        else{
            for(int j=n;j>=1;j--){
                if(a[cnt--]!=x) continue;
                else{
                   cout<<i<<" "<<j;
                   return 0;
                }
            }flag=true;
        }
    }
	return 0;
}
