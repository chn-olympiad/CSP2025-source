#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],cnt;
int ans[500007][2];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int xo=0;
			for(int z=i;z<=j;z++)xo^=a[z];
			if(xo==k){
				int flag=1;
				for(int s=0;s<cnt;s++){
					if((ans[s][0]<=i and ans[s][1]>=i) or (ans[s][0]<=j and ans[s][1]>=j)){
						flag=0;
						break;
					} 
				}
				if(flag){
					ans[cnt][0]=i;
					ans[cnt][1]=j;
					cnt++;
				} 
			} 
		}
	}
	cout<<cnt;
	return 0;
}
