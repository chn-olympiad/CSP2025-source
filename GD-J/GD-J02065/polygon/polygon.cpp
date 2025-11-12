#include<bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n<=10){
		if(n>=3) 
		for(int j=1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		if(n>=4) 
		for(int b=1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		if(n>=5) 
		for(int c=1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		if(n>=6) 
		for(int d=1;d<=n-5;d++)
		for(int c=d+1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[d]+a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		for(int e=1;e<=n-6;e++)	
		for(int d=e+1;d<=n-5;d++)
		for(int c=d+1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=7;i<=n&&i>=k;i++){
			if(a[e]+a[d]+a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		for(int f=1;f<=n-7;f++)	
		for(int e=f+1;e<=n-6;e++)	
		for(int d=e+1;d<=n-5;d++)
		for(int c=d+1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[f]+a[e]+a[d]+a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		for(int g=1;g<=n-8;g++)	
		for(int f=g+1;f<=n-7;f++)	
		for(int e=f+1;e<=n-6;e++)	
		for(int d=e+1;d<=n-5;d++)
		for(int c=d+1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[f]+a[g]+a[e]+a[d]+a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
		for(int h=1;h<=n-9;h++)	
		for(int g=h+1;g<=n-8;g++)	
		for(int f=g+1;f<=n-7;f++)	
		for(int e=f+1;e<=n-6;e++)	
		for(int d=e+1;d<=n-5;d++)
		for(int c=d+1;c<=n-4;c++)
		for(int b=c+1;b<=n-3;b++)
		for(int j=b+1;j<=n-2;j++)
		for(int k=j+1;k<=n-1&&k>=j;k++)
		for(int i=k+1;i<=n&&i>=k;i++){
			if(a[h]+a[f]+a[g]+a[e]+a[d]+a[c]+a[b]+a[j]+a[k]+a[i]>2*a[i]){
				ans++;
			}else break;
		}
	}
	cout<<ans;
	return 0;
}

