#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
int n;
int t;
cin>>t;
int sum,sum1=0,maxn;
int b[t]={0};
int a[100001][3];
for(int i=1;i<=t;i++){
	cin>>n;

	for(int j=1;j<=n;j++){
		for(int u=1;u<=3;u++){
			cin>>a[j][u]>>endl;
		}
}
}
//for(int i=1;i<=n;i++){
//	for(int j=1;j<=3;j++){
//		cout<<a[i][j]<<endl;
//	}
//}

//for(int a1=1;a1<=3;a1++){
//	for(int a2=1;a2<=3;a2++){
//	sum=a[1][a1]+a[2][a2];
//	if(a1==a2){
//		sum=0;
//	}else{	
// 		maxn=max(sum,sum1);
//		sum1=sum;
//	}
//}
//
//}
//
//for(int p=1;p<=t;p++){
//	b[p]=maxn;
//}
//}
//for(int p=1;p<=t;p++){
//	cout<<b[p]<<endl;
//}

	return 0;
}
