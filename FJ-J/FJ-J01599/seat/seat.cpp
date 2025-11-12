#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[110];
int n,m,o=1,p,ans,ans1;
bool cmp(long long x,long long y){
	if(x>y) return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0];
	p=a[0];
	while(cin>>a[o]){
		o++;
	}
	sort(a,a+o,cmp);
	for(int i=0;i<o;i++){
		if(a[i]==p){
			ans1=i+1;
			break;
		}
	}
	ans=ans1%n;
	//cout<<ans<<endl;
	if(ans1/n%2==0&&ans1%n!=0){
		cout<<ans1/n+1<<" "<<ans;
	}else if(ans1/n%2==1&&ans1%n!=0){
		cout<<ans1/n+1<<" "<<n-ans+1;
	}else cout<<ans1/n<<" "<<n;
	return 0;
} 
