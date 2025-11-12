#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int s=0,max=0,cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	
	if(n<=3){
		for(int i=0;i<3;i++){
			if(a[i]>max)max=a[i];
			s+=a[i];
		}
		if(s>max*2)cnt+=1;
	}
	cout<<cnt;
	return 0;
}
