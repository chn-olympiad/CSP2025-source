#include<bits/stdc++.h>
using namespace std;
int n,a[10010],he,ans,p[510],h[510][510];//个//从小到大;p第k个记录到哪里了 
void sss(int hh,int k,int w,int K){//找K个数，记录和hh，当前在第w个,还要找k个 
	if(k==0)h[K][++p[K]]=hh; 
	for(int i=w+1;i<=n;i++){
		sss(hh+a[i],k-1,i,K);
	} 
	return; 
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	//判断 
	if(n<3){
		cout<<0;
		return 0;
	}
	//求和 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		he+=a[i];
	}
	sort(a+1,a+1+n);//从小到大
	//求和
	for(int k=2;k<=n-1;k++){//选k个数 
		sss(0,k,0,k);
	} 
	
	
	for(int k=n;k>=3;k--){//枚举MAx 
		if(a[k]*2>=he)continue;
		for(int i=2;i<=n-1;i++){
			for(int j=1;j<=p[i];j++){
				if(k<h[i][j])ans++;
			}
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
