#include<bits/stdc++.h>
using namespace std;
int t,ans[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,a[100005][4],b[100005],m,max1=0,max2=0,max3=0;
		cin>>n;
		memset(a,0,sizeof(a));
		int flag1=1,flag2=1;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			b[j]=a[j][1];
			if(a[j][2]!=0||a[j][3]!=0){
				flag1=0;
			}
			if(a[j][3]!=0){
				flag2=0;
			}
		}
		m=n/2;
		if(flag1==1){
			sort(b+1,b+n+1);
			for(int j=n;j>=m;j--){
				ans[i]+=b[j];
			}
			continue;
		}else if(n==2){
			for(int x=1;x<=3;x++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						ans[i]=max(ans[i],a[1][x]+a[2][j]);
					}
				}
			}
		}else if(n==4){
			for(int x=1;x<=3;x++){
			if(x==1){max1++;}if(x==2){max2++;}if(x==3){max3++;}
				for(int j=1;j<=3;j++){
					if(j==1){max1++;}if(j==2){max2++;}if(j==3){max3++;}
					for(int l=1;l<=3;l++){
						if(l==1){max1++;}if(l==2){max2++;}if(l==3){max3++;}
						for(int r=1;r<=3;r++){
							if(r==1){max1++;}if(r==2){max2++;}if(r==3){max3++;}
							if(max1>2||max2>2||max3>2){
								max1=max2=max3=0;
								continue;
							}else{
								ans[i]=max(ans[i],a[1][x]+a[2][j]+a[3][l]+a[4][r]);
							}
						}
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(a[k][1]>a[j][1]){
					swap(a[k][1],a[j][1]);
					swap(a[k][2],a[j][2]);
					swap(a[k][3],a[j][3]);
				}else if(a[k][1]==a[j][1]&&a[k][2]>a[j][2]){
					swap(a[k][1],a[j][1]);
					swap(a[k][2],a[j][2]);
					swap(a[k][3],a[j][3]);
				}else if(a[k][1]==a[j][1]&&a[k][2]==a[j][2]&&a[k][3]>a[j][3]){
					swap(a[k][1],a[j][1]);
					swap(a[k][2],a[j][2]);
					swap(a[k][3],a[j][3]);
				}
			}
		}
		if(flag2==1){
			for(int j=1;j<=n;j++){
				max1++;
				if(max1<=m){
					ans[i]+=a[j][1];
				}
				if(max1>m){
					max2++;
					if(max2<=m){
						ans[i]+=a[j][2];
					}
				}
			}
			continue;
		}else{
			for(int j=1;j<=n;j++){
				ans[i]+=max(max(a[j][1],a[j][2]),a[j][3]);
			}
	}
}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
