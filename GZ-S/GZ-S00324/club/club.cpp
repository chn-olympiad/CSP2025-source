//GH-S00324 六盘水市第四实验中学 王梓懿 
#include<bits/stdc++.h>
using namespace std;
int sum=0;
int n,a[100005][3],big[100005],c1[100005],c2[100005],c3[100005],biggest[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(biggest[i]<a[i][j]){
				biggest[i]=a[i][j];
				big[i]=j;
				sum+=a[i][j];
			}
		}
	}
	cout<<sum; 
	return 0; 
}
