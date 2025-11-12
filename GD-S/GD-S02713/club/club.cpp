#include<bits/stdc++.h>
using namespace std;
struct link{
	int one,two,three;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int k=1;k<=n;k++){
		int m,sum=0;
		link a[100005];
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i].one>>a[i].two>>a[i].three;
		}
		for(int i=1;i<=m;i++){
			sum+=max(max(a[i].one,a[i].two),a[i].three);
		}
		cout<<sum<<endl;
	}
	return 0;
} 
