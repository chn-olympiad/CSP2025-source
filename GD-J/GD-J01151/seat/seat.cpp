#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=12;
int n,m,x,k,a[N*N],ans_x=1,ans_y=1,temp=1;
bool flag=true;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++)
    	scanf("%lld",&a[i]);
    x=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
    	if(a[i]==x) k=i;
    for(int i=1;i<k;i++){
    	if(flag==true){
    		ans_y+=temp;
			flag=false;
			continue;
		}
		if(ans_y==n){
    		temp=-1;
    		flag=true;
    		ans_x++;
    		continue;
		}
		if(ans_y==1){
    		temp=1;
    		flag=true;
    		ans_x++;
    		continue;
		}
		ans_y+=temp;
	}
	printf("%lld %lld",ans_x,ans_y);
	return 0;
}

