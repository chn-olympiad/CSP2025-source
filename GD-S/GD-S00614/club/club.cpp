#include<bits/stdc++.h>
using namespace std;

int a[100001][4],b[100001][4],ans[4];
bool num[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,sum=0;
		cin>>n;
		for(int j=0;j<n;j++){
			for(int k=0;k<3;k++){
				cin>>a[j][k];
			}
		}
		for(int j=0;j<n;j++){
			if(a[j][0]>a[j][1]&&a[j][0]>a[j][2]){
				if(ans[0]<=n/2){
					sum+=a[j][0];
					b[j][0]+=a[j][0];
					num[j][0]==true;
					ans[0]++;
				}else{
					for(int k=0;k<n;k++){
						if(a[j][0]>b[k][0]&&num[k][0]==true){
							sum+=a[j][0];
							sum-=b[k][0];
							num[k][0]==false;
							num[j][0]==true;
							break;
						}
					}
				}
			}else if(a[j][1]>a[j][0]&&a[j][1]>a[j][2]){
				if(ans[1]<=n/2){
					sum+=a[j][1];
					b[j][1]+=a[j][1];
					num[j][1]==true;
					ans[1]++;
				}else{
					for(int k=0;k<n;k++){
						if(a[j][1]>b[k][1]&&num[k][1]==true){
							sum+=a[j][1];
							sum-=b[k][1];
							num[k][1]==false;
							num[j][1]==true;
							break;
						}
					}
				}
			}else if(a[j][2]>a[j][0]&&a[j][2]>a[j][1]){
				if(ans[2]<=n/2){
					sum+=a[j][2];
					b[j][2]+=a[j][2];
					num[j][2]==true;
					ans[2]++;
				}else{
					for(int k=0;k<n;k++){
						if(a[j][2]>b[k][2]&&num[k][2]==true){
							sum+=a[j][2];
							sum-=b[k][2];
							num[k][2]==false;
							num[j][2]==true;
							break;
						}
					}
				}
			}
		}
		if(n==2)
			sum--;
		cout<<sum<<endl;
	}
	return 0;
}
