#include<bits/stdc++.h>
using namespace std;
int n,a[100005],cnt[4],hum[100005],ans,l;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	cin>>n;
	l=0;
	for(int i=1;i<=n;i++){
			cin>>a[i]>>cnt[1]>>cnt[2];
	}
	sort(a+1,a+1+n);
	for(int i=n,j=1;j<=n/2;j++,i--){
		cout<<a[i]<<endl;
	}
} 
}
