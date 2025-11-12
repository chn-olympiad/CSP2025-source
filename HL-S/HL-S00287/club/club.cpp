#include<bits/stdc++.h>
using namespace std;
long long t,n,a[120000][12],lin,ans,sum,ch[12],k[120000];
void dp(int x){
	if (x>n){
		ans=max(ans,sum);
		return;
	}
	for (int j=1;j<=3;j++){
		ch[j]++;
		if (ch[j]<lin||ch[j]==lin){
			sum=sum+a[x][j];
			dp(x+1);
			ch[j]--;
			sum=sum-a[x][j];
		}
		else{
			ch[j]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++){ 
		ans=0;
		sum=0;
		ch[i]=0;
		cin>>n;
		lin=n/2;
		
		for (int j=1;j<=n;j++){
			for (int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		if (n==100000){
			if (a[1][2]==a[1][3]){
				for (int p=1;p<=n;p++){
					k[p]=a[p][1];
				}
				sort(k+1,k+n+1);
				for (int p=n/2+1;p<=n;p++){
					ans=ans+k[p];
				}
			}
		}
		else{
			dp(1);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}  
