#include <bits/stdc++.h>
using namespace std;
int ans=0,a[5010],n;
int q[10000]={},top=0;
bool check=false;
bool isok(){
	long long p=0;
	for(int i=1;i<top;i++){
		p+=a[q[i]];
		if(p>a[q[top]]){
			return true;
		}
	}
	return false;
}
void yy(int m){
	if(m==0){
		if(isok()==true){
			ans++;
			ans%=998244353;
		}else{
			check=true;
		}
		return;
	}
	top++;
	for(int i=q[top-1]+1;i<=n;i++){
		q[top]=i;
		yy(m-1);
		if(m==1&&check==true){
			break;
		}
	}
	check=false;
	top--;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		yy(i);
	}
	cout<<ans;
	return 0;
}
