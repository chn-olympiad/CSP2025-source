#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[10005];
bool cmp(int n1,int n2){
	return n1>n2;
}
int main(){
freopen ("seat.in","r",stdin);
freopen ("seat.out","w",stdout);
ios::sync_with_stdio(0);
cin>>n>>m;
for (int i=1;i<=n*m;i++)cin>>s[i];
int k=s[1];
sort(s+1,s+n*m+1,cmp);
int flag=0;
for (int i=1;i<=n*m;i++){
	if (k==s[i]){
		flag=i;
		break;
	}
	}
    int x=flag/n;
    int y=flag%n;
    if (y==0){
		cout<<x<<" "<<n<<endl;
		return 0;
	}
	if (y!=0){
		if (x%2==0)cout<<x+1<<" "<<y<<endl;
		else cout<<x+1<<" "<<1+n-y<<endl;
		return 0;
	}
	return 0;
}
