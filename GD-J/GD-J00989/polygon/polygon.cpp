#include<bits/stdc++.h>
using namespace std;
vector<int> l;
int n;
int a[5001];
long long cnt=0,ans=0;
void nm(int now,int m){
	if(m==0){
		if(cnt>l[l.size()-1]*2){
			ans++;
		}
		return;
	}
	for(int i=now+1;i<=n-m;i++){
		l.push_back(a[i]);
		cnt+=a[i];
		nm(i,m-1);
		l.pop_back();
		cnt-=a[i];
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=3;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			l.push_back(a[j]);
			cnt+=a[j];
			nm(j,i-1);
			l.pop_back();
			cnt-=a[j];
		}
	}
	cout<<ans%998224353;
	return 0;
}
