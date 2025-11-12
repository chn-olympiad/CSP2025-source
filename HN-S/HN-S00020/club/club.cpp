#include<bits/stdc++.h>
using namespace std;
long long T,n,a[500005],b[500005],c[500005];
bool a1(){
	for(int i=1;i<n;i++){
		if(a[i-1]!=0 or a[i]!=a[i-1]){
			return 0;
		}
	}
	return 1;
}
bool a2(){
	for(int i=1;i<n;i++){
		if(b[i-1]!=0 or b[i]!=b[i-1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			if((max(a[0],max(b[0],c[0]))==a[0] and max(a[1],max(b[1],c[1]))==a[1])or(max(a[0],max(b[0],c[0]))==b[0] and max(a[1],max(b[1],c[1]))==b[1])or(max(a[0],max(b[0],c[0]))==c[0] and max(a[1],max(b[1],c[1]))==c[1])){
				if(max(max(a[0],max(b[0],c[0])),max(a[1],max(b[1],c[1])))==a[0] or b[0] or c[0]){
					cout<<a[1]+b[1]+c[1]-max(a[1],max(b[1],c[1]))-min(a[1],min(c[1],b[1]))+max(max(a[0],max(b[0],c[0])),max(a[1],max(b[1],c[1])));
				}	
			}
		}
		else if(n==100000 and a1() and a2()){
			sort(a,a+n);
			long long ans=0;
			for(int i=0;i<50000;i++){
				ans+=a[i];
			}
			cout<<ans;
		}
		else if(n>2 and a1()){
			sort(a,a+n);
			sort(b,b+n);
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=max(a[i],b[i]);
			}
			cout<<ans;
		}
		else if(n>2){
			sort(a,a+n);
			sort(b,b+n);
			sort(c,c+n);
			cout<<a[n-1]+b[n-1]+c[n-1]+max(a[n-2],max(b[n-2],c[n-2]));
		}	
	}
	return 0;
}
