#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,a[6000],ans=0;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3])
		{
			ans=1;
			cout<<ans;
			return 0;
		}
		else{
			cout<<ans;
			return 0;
		}
	}//3根的情况
	int al=0;
	for(int i=1;i<=n;i++){
		al=al+a[i];
	} 
	if(al<=a[n]*2){
		cout<<ans;
		return 0;
	}//不能拼成 
	int lt=1,rt=3,l=1,r=3,d=3;
	while(d<n){
		l=lt;
		r=rt;
		while(r<=n){
			al=0;
			for(int i=l;i<=r;i++){
				al=al+a[i];
			} 
			if(al>a[r]*2){
				ans++;
				
			}
			l++;
			r++;
		}
		d++;
		rt=lt+d-1;
	}
	cout<<ans;
	return 0;
}