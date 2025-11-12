#include<bits/stdc++.h>
using namespace std;
int pa[10000010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>pa[i];
    sort(pa+1,pa+n+1);
    int left=1,right=n;
    while(left<right){
		int mid=(left+right)/2;
		if(mid<=pa[mid-1]+1) {
			left=mid+1;
		}
		else if(mid>pa[mid-1]+1){
			right=mid-1;
		} 
	}
	int f=n-right+1;
	cout<<max(f,m);
    return 0;
}
