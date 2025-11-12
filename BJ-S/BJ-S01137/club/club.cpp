#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10; 

int t;
int a[N],b[N],c[N];
bool cmp(int x, int y){return x>=y;}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;

	while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        int sum=0;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n/2;i++)
			sum+=a[i];
		cout<<sum;
	}
	

	return 0;
}
