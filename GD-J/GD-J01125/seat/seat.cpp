#include<bits/stdc++.h>
using namespace std;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],t,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,f=0;
	while(1){
		cnt++;
		if(t==a[cnt]){
			cout<<j<<" "<<i;
			return 0;
		}
		if(i<n&&!f) i++;
		else if(i==n&&!f) j++,f=1;
		else if(i>1&&f) i--;
		else if(i==1&&f) j++,f=0;
	}
	return 0;
}
