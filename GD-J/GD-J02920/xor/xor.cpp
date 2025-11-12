#include<iostream>
#include<cstdio>
#include<iomanip>
#include<math.h>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
LL n,k,a[N],ad[N];
LL st;
LL ar[st],ed[st];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}ar[++st]=1;
	ad[st]=a[1];
	if(ad[st]==k)st++;//cout<<1;
	for(int i=2;i<=n;i++){
		ad[st]^=a[i];
		if(ad[st]==k){
			if(a[i+1]==0&&a[i+2]==0){
				i+=2;
			}else if(a[i+1]==0&&a[ar[st]]==0)i+=1;
			st++;
			ad[st]=a[i+1];
			i++;
//			cout<<i;
		}
	}
	cout<<st-1;
}

