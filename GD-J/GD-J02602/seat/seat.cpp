#include<bits/stdc++.h>
using namespace std;
int n,m,R,a[105];
int flag;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	R=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			flag=i;
			break;
		}
	}
	//ÁÐ 
	int li_e=flag/n;
	if(flag%n!=0) li_e++; 
	//ÐÐ
	int han_g=flag%n;
	if(han_g==0) han_g=n;
	if(li_e%2==1) cout<<li_e<<" "<<han_g;
	else cout<<li_e<<" "<<n-han_g+1;
	return 0;
}
