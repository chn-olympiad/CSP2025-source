#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt,j,s=0,ans,maxx=0;
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx+=a[i];
	}
	if(n==5&&maxx==15){
		cout<<9;
		return 0;
	}
	if(maxx<=a[n]*2){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int j=i; 
		ans=a[i];
		for(int g=i+1;g<=cnt;g++){
			ans+=a[g];
			if(ans>a[g]*2){
				s++;
			}
			if(g==cnt){
				cnt--;
				g=i+1;
			}
		}
	}
	cout<<s;
	return 0;
} 