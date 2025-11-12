#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int N=5e5+5;
int n,k,a[N],s;
ll ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s^=a[i];
		a[i]=s;
	}
	int last=0;
	for(int i=1;i<=n;++i){
		for(int j=0;i+j<=n;++j){
			if((a[i+j]^a[i-1])==k){
				if(i<=last){
					if(i+j<last){
						last=i+j;
					}
				}else{
					++ans;
					last=i+j;
				}
				break;
			}
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

