
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][4],t,mx=-0x3f3f3f3f;
int num[4];
void search(int t,int sum){
	if(t>n){
		mx=max(mx,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(num[i]>=n/2) continue;
		num[i]++;
		search(t+1,sum+a[t][i]);
		num[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		num[1]=0;
		num[2]=0;
		num[3]=0;
		mx=-0x3f3f3f3f;
		search(1,0);
		cout<<mx<<endl;
	}
	return 0;
}
