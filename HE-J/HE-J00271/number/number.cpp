#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	
	int l=s1.size();
	int a[100005]={0};
	
	int b=0,c;
	for(int i=l-1;i>=0;i--){
		if(s1[i]>=48&&s1[i]<=57){
			a[b]=s1[i]-'0';
			b++;	
		}
	}
	for(int i=b;i<=0;i++){
		for(int j=b;j<=0;i++){
			if(a[i]<a[j]){
				c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}	
	}
	int ans=0;
	for(int i=0;i<=b;i++){
		int d=1;
		for(int j=i;j<b-1;j++){
			d*=10;
		}
		ans+=a[i]*d;
	}
	cout<<ans;
	return 0;
} 
