#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long ans=0;
int n,k;
struct sss{
	int a;
	bool f=0;
};
sss arr[maxn];
int a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int maxn=0;
	int pre=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==k){
			ans++;
//			cout<<i<<"\n";
		    arr[i].f=1;
		    maxn=max(maxn,i-pre);
		    pre=i;
        }
		arr[i].a=a;
	}
	maxn=max(maxn,n-pre);
	for(int i=1;i<maxn;i++){
        for(int j=1;j+i<=n;j++){
        	int sum=0;
        	for(int h=0;h<=i;h++){
        		if(arr[j+h].f){
					goto flag;
				}
        		sum^=arr[j+h].a;
			}
			if(sum==k){
				ans++;
				for(int h=0;h<=i;h++){
					arr[j+h].f=1;
				}
				continue;
			}
			flag:
				continue;
		}
    }
	cout<<ans<<"\n";																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																					
	return 0;
}
