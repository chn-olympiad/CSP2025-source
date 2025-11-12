#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int sum[100001];
long long s[30001];

//int d[8001][8001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n==3){
		if(arr[1]+arr[2]>arr[3]&&arr[2]+arr[3]>arr[1])cout<<1;
		else cout<<0;
	}else if(n<=2){
		cout<<0;
	}else{
//		sort(arr+1,arr+1+n);
//		for(int i=1;i<=n;i++){
//			sum[i]=arr[i]+sum[i-1];
//		}
//		for(int i=1;i<=n-2;i++){
//			mx[i][2]=max(max(arr[i],arr[i+1]));
//			if(arr[i]+arr[i+1]>arr[i+2]&&arr[i+1]+arr[i+2]>arr[i])dp[i][2]=1;
//		}
//		for(int i=3;i<=n;i++){
//			for(int l=1;i+l-1<=n;l++){
//				r=l+i-1;
//				for(int k=l;k<=r;k++){
//					dp[l][i]=
//				}
//				
//			}
//		}
		sort(arr+1,arr+1+n);
		for(int i=1;i<=n;i++){
			sum[i]=arr[i]+sum[i-1];
		}
		int ans=0;
		for(int i=3;i<=n;i++){
			for(int l=2;l<i;l++){
				for(int k=1;k<l;k++){
					if(arr[i]<arr[l]+arr[k])ans++;
				}
			}
		}
		for(int i=4;i<=n;i++){
			for(int l=3;l<i;l++){
				for(int k=2;k<l;k++){
					for(int p=1;p<k;p++){
						if(arr[i]<arr[p]+arr[l]+arr[k])ans++;
					}
				}
			}
		}
		for(int e=5;e<=n;e++){
			for(int i=4;i<e;i++){
				for(int l=3;l<i;l++){
					for(int k=2;k<l;k++){
						for(int p=1;p<k;p++){
							if(arr[e]<arr[i]+arr[p]+arr[l]+arr[k])ans++;
						}
					}
				}
			}
		}
		for(int w=6;w<=n;w++){
		for(int e=5;e<w;e++){
			for(int i=4;i<e;i++){
				for(int l=3;l<i;l++){
					for(int k=2;k<l;k++){
						for(int p=1;p<k;p++){
							if(arr[w]<arr[e]+arr[i]+arr[p]+arr[l]+arr[k])ans++;
						}
					}
				}
			}
		}
		for(int v=7;v<=n;w++){
		for(int w=6;w<v;w++){
		for(int e=5;e<w;e++){
			for(int i=4;i<e;i++){
				for(int l=3;l<i;l++){
					for(int k=2;k<l;k++){
						for(int p=1;p<k;p++){
							if(arr[v]<arr[w]+arr[e]+arr[i]+arr[p]+arr[l]+arr[k])ans++;
						}
					}
				}
			}
		}
	}
}
	}
		cout<<ans;
	}
	return 0;
}
