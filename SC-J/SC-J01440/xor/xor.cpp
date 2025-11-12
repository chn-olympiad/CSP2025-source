#include<bits/stdc++.h>
typedef unsigned int ui;
using namespace std;

ui n,k,a[500005],ans;
int sum(ui st,ui ed,ui array[]){
	ui tmp = array[st];
	for(ui i = st+1;i <= ed;i++){
		tmp = tmp^array[i];
	}
	return tmp;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ui i = 1;i<=n;i++)cin>>a[i];
	for(ui i = 1;i<=n;i++) 
		for(ui j = i;j<=n;j++){
			if(sum(i,j,a)==k){
				ans++;i=j;break;
			}
		}
	cout<<ans;
	return 0;
} 
