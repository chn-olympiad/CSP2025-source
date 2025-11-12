#include<bits/stdc++.h>
using namespace std;
bool cmp(int l,int r){
	return l>r;
}
int a[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int nijika=a[1],daisuki;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		//cout<<a[i]<<' ';
		if(a[i]==nijika){
			daisuki=i;
			break;
		}
	}
	//cout<<'\0';
	int ans1=daisuki/n;
	if(daisuki%n!=0)ans1++;
	int a2=(daisuki-1)%n,ans2;
	//cout<<a2<<' '<<daisuki<<'\0';
	if(ans1%2==0)ans2=n-a2;
	else ans2=a2+1;
	cout<<ans1<<' '<<ans2<<'\0';
	return 0;
}
