#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,a[100010];
pair<int,int> p[1001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int s=a[1],t=0,ans=0;
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				++ans;
				p[ans].first=i;p[ans].second=j;
			}
		}else{
			for(int i=1;i<=n;i++){
				++ans;
				p[ans].first=i;p[ans].second=j;
			}
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==s){
			t=i;break;
		}
	cout<<p[t].second<<" "<<p[t].first<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
